USE
    [database];
GO;

/* ------------------------- Customer -------------------------*/

/* Query to fill CustomerPage */
SELECT id_customer,
       last_name,
       first_name,
       CONVERT(VARCHAR(10), birthdate, 103) AS birthdate
FROM customer;
/*
WHERE deleted = 0;*/

/* Query to insert new customer */
INSERT INTO customer (last_name, first_name, birthdate)
VALUES ('aa', 'bb', 'cc');

/* Query to update a customer */
UPDATE customer
SET last_name  = 'aa',
    first_name = 'bb',
    birthdate  = 'cc'
WHERE id_customer = 1;

/* Query to delete user (set "deleted" to 1) */
UPDATE customer
SET deleted = 1
WHERE id_customer = 1;

/* Query to really delete customer (in case of cancel) */
DELETE
FROM customer
WHERE id_customer = 1;

/* ------------------------- Addresses -------------------------*/

/* Query to get addresses from a client */
SELECT a.id_address,
       a.street,
       a.zip_code,
       a.city,
       at.id_address_type,
       at.type
FROM address a
         INNER JOIN customerHasAddress cha ON a.id_address = cha.id_address
         INNER JOIN address_type at
                    ON cha.id_address_type = at.id_address_type
WHERE a.deleted = 0
  AND cha.id_customer = 1;

/* Query to insert new address */
INSERT INTO address (street, zip_code, city)
VALUES ('aa', 'bb', 'cc');

INSERT INTO customerHasAddress (id_customer, id_address, id_address_type)
VALUES (1, 1, 1);

/* Query to delete an address */
UPDATE address
SET deleted = 1
WHERE id_address = 1;

/* query to update an address = delete + insert*/

/* ------------------------- Catalog -------------------------*/

/* Query to fill CatalogPage */
SELECT id_product,
       deleted,
       reference,
       type,
       name,
       colour,
       buy_price,
       vat_rate,
       quantity,
       provisioning_threshold
FROM product;

/* Query to fill TieredPrices */
SELECT minimal_quantity,
       tf_price,
       ROUND(tf_price * (1 + vat_rate / 100), 3) AS price
FROM tiered_price
         INNER JOIN product p ON tiered_price.id_product = p.id_product
WHERE p.deleted = 0
  AND p.id_product = 1;

/* ------------------------- Orders -------------------------*/

/* Query to fill OrdersPage */

/* have the sum of ohp.price only count prices when validated is true in the table *payment* */
SELECT o.id_order,
       o.reference,
       c.last_name,
       c.first_name,
       CONVERT(VARCHAR(10), c.birthdate, 103)              AS birthdate,
       CONVERT(VARCHAR(10), o.issue_date, 103)             AS issue_date,
       CONVERT(VARCHAR(10), o.expected_delivery_date, 103) AS expected_delivery_date,
       CONCAT(b.street, ', ', b.zip_code, ', ', b.city)    AS billing_address,
       CONCAT(d.street, ', ', d.zip_code, ', ', d.city)    AS delivery_address,
       ROUND(SUM(ohp.price), 3)                            AS total_amount,
       ROUND((SELECT SUM(amount) FROM payment WHERE id_order = o.id_order AND validated = 1),
             3)                                            AS payed_amount,
       CONVERT(VARCHAR(10), IIF((SELECT ROUND(SUM(amount), 3)
                                 FROM payment
                                 WHERE id_order = o.id_order AND validated = 1) = ROUND(SUM(ohp.price), 3),
                                (SELECT MAX(payment_date) FROM payment WHERE id_order = o.id_order), NULL),
                            103)                           AS payment_date,
       ROUND(SUM(ohp.vat_price), 3)                        AS vat_amount,
       ROUND(SUM(ohp.tf_price), 3)                         AS tf_amount
FROM [order] o
         INNER JOIN customer c
                    ON o.id_customer = c.id_customer
         INNER JOIN address b ON o.id_billing_address = b.id_address
         INNER JOIN address d ON o.id_delivery_address = d.id_address
         INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order
WHERE o.deleted = 0
GROUP BY o.id_order, o.reference, o.issue_date, o.expected_delivery_date, c.last_name, c.first_name, c.birthdate,
         b.street, b.zip_code, b.city, d.street, d.zip_code, d.city;

/* Query to fill OrderDetails */
SELECT p.type,
       p.name,
       p.colour,
       ohp.quantity,
       ohp.tf_price,
       ohp.price
FROM product p
         INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product
WHERE p.deleted = 0
  AND ohp.id_order = 2
ORDER BY ohp.quantity DESC;

/* Query to fill PaymentsForm */
SELECT id_payment,
       id_order,
       CONVERT(VARCHAR(10), payment_date, 103) AS payment_date,
       payment_mean,
       amount,
       validated
FROM payment
WHERE id_order = 2
ORDER BY payment_date;

/* Query to update a payment */
UPDATE payment
SET payment_date = '2010-10-10',
    payment_mean = 'CB',
    amount       = '5',
    validated    = 'True'
WHERE id_payment = 2;

/* Query to insert a payment */
INSERT INTO payment (id_order, payment_date, payment_mean, amount, validated)
VALUES (2, '2010-10-10', 'CB', '5', 'True');

/* Query to delete a payment */
DELETE
FROM payment
WHERE id_payment = 2;

/* Query to fill OrderForm */

SELECT p.id_product,
       p.type,
       p.name,
       p.colour,
       ohp.quantity,
       ohp.price
FROM product p
         INNER JOIN dbo.orderHasProduct ohp on p.id_product = ohp.id_product
WHERE id_order = 1;

SELECT p.id_product, p.type, p.name, p.colour, ohp.quantity, ohp.price
FROM product p
         INNER JOIN dbo.orderHasProduct ohp on p.id_product = ohp.id_product
WHERE id_order = 1;


/* Query to calculate the average order total price */

SELECT total_amount AS average_order_total_price
FROM (SELECT ROUND(SUM(ohp.price), 3) / COUNT(o.id_order) AS total_amount
      FROM [
      order] o
               INNER JOIN customer c
                          ON o.id_customer = c.id_customer
               INNER JOIN address b ON o.id_billing_address = b.id_address
               INNER JOIN address d ON o.id_delivery_address = d.id_address
               INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order
      WHERE o.deleted = 0) AS total_amount;

/* Query to calculate the turnover for a given month */

SELECT ROUND((SUM(ohp.price) - SUM(p.buy_price)), 3) AS turnover
FROM [
order] o
         INNER JOIN customer c
                    ON o.id_customer = c.id_customer
         INNER JOIN address b ON o.id_billing_address = b.id_address
         INNER JOIN address d ON o.id_delivery_address = d.id_address
         INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order
         INNER JOIN product p ON ohp.id_product = p.id_product
WHERE o.deleted = 0
  AND MONTH(o.issue_date) = 2
  AND YEAR(o.issue_date) = 2014;

/* Query to find all products where the quantity is below the restocking threshold */

SELECT p.id_product,
       p.reference,
       p.type,
       p.name,
       p.colour,
       p.buy_price,
       p.vat_rate,
       p.quantity,
       p.provisioning_threshold
FROM product p
WHERE p.deleted = 0
  AND p.quantity < p.provisioning_threshold;

/* Calculate sum of purchases costs for a given customer */

SELECT ROUND(SUM(ohp.price), 3) AS sum_of_purchases_costs
FROM [
order] o
         INNER JOIN customer c
                    ON o.id_customer = c.id_customer
         INNER JOIN address b ON o.id_billing_address = b.id_address
         INNER JOIN address d ON o.id_delivery_address = d.id_address
         INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order
WHERE o.deleted = 0
  AND c.last_name = 'Gillet'
  AND c.first_name = 'Mathieu'
  AND c.birthdate = '2023-12-27';

/* Query to find the 10 most sold products */

SELECT TOP 10 p.reference,
              p.type,
              p.name,
              p.colour,
              p.buy_price,
              p.vat_rate,
              p.quantity,
              p.provisioning_threshold,
              SUM(ohp.quantity) AS quantity_sold
FROM product p
         INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product
GROUP BY p.reference,
         p.type,
         p.name,
         p.colour,
         p.buy_price,
         p.vat_rate,
         p.quantity,
         p.provisioning_threshold
ORDER BY SUM(ohp.quantity) DESC;

/* Query to find the 10 least sold products */

SELECT TOP 10 p.reference,
              p.type,
              p.name,
              p.colour,
              p.buy_price,
              p.vat_rate,
              p.quantity,
              p.provisioning_threshold,
              SUM(ohp.quantity) AS quantity_sold
FROM product p
         INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product
GROUP BY p.reference,
         p.type,
         p.name,
         p.colour,
         p.buy_price,
         p.vat_rate,
         p.quantity,
         p.provisioning_threshold
ORDER BY SUM(ohp.quantity) ASC;

/* Query to find the total buy price value of the current stock */

SELECT SUM(p.buy_price * p.quantity) AS total_buy_price_value_of_current_stock
FROM product p
WHERE p.deleted = 0;

/* Query to find the turnover of the current stock */
/* order of parameters : margin, vat rate, sale, possible losses */

SELECT s.id_staff,
       s.last_name,
       s.first_name,
       CONVERT(VARCHAR(10), s.hire_date, 103),
       a.street,
       a.zip_code,
       a.city,
       b.last_name,
       b.first_name
FROM staff s
         INNER JOIN address a on a.id_address = s.id_address
         LEFT JOIN staff b on b.id_staff = s.id_staff_boss
WHERE s.deleted = 0;

SELECT TOP 1 CONVERT(VARCHAR(10), issue_date, 103) AS first_order_date
FROM [
order]
         INNER JOIN customer c
                    ON [
order].id_customer = c.id_customer
WHERE c.last_name = 'Gillet'
  AND c.first_name = 'Mathieu';

SELECT p.type, p.name, p.colour, ohp.quantity, ohp.tf_price, + ohp.price
FROM product p
         INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product
WHERE p.deleted = 0
  AND ohp.id_order = 1007
ORDER BY ohp.quantity DESC;



SELECT CONCAT(street, ', ', zip_code, ', ', city) AS delivery_address
FROM address
WHERE CONCAT(street, ', ', zip_code, ', ', city) LIKE '%'
  AND id_address IN (SELECT id_address
                     FROM customerHasAddress
                     WHERE id_customer =
                           (SELECT id_customer FROM customer WHERE last_name = 'Leonie' AND first_name = 'Mathice') AND
                           (id_address_type = 2
                        OR id_address_type = 3))
  AND deleted = 0;

SELECT CONVERT(VARCHAR(10), birthdate, 103) AS birthdate FROM customer WHERE last_name = 'Leonie' AND first_name = 'Mathice';

SELECT TOP 1 CONVERT(VARCHAR(10), issue_date, 103) AS first_order_date FROM [order] INNER JOIN customer c ON [order].id_customer = c.id_customer WHERE c.last_name = 'Laumel' AND c.first_name = 'Stephan' ORDER BY issue_date ASC;

