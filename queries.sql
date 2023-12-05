USE [database];
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
         INNER JOIN address_type at ON cha.id_address_type = at.id_address_type
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
       ROUND(tf_price * (1 + vat_rate / 100), 2) AS price
FROM tiered_price
         INNER JOIN product p ON tiered_price.id_product = p.id_product
WHERE p.deleted = 0
  AND p.id_product = 1;

/* ------------------------- Orders -------------------------*/

/* Query to fill OrdersPage */
SELECT o.id_order,
       o.reference,
       c.last_name,
       c.first_name,
       CONVERT(VARCHAR(10), c.birthdate, 103)                        AS birthdate,
       CONVERT(VARCHAR(10), o.issue_date, 103)                       AS issue_date,
       CONVERT(VARCHAR(10), o.expected_delivery_date, 103)           AS expected_delivery_date,
       CONCAT(b.street, ', ', b.zip_code, ', ', b.city)              AS billing_address,
       CONCAT(d.street, ', ', d.zip_code, ', ', d.city)              AS delivery_address,
       SUM(ohp.price)                                                AS total_amount,
       (SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) AS payed_amount,
       CONVERT(VARCHAR(10), IIF((SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) = SUM(ohp.price),
                                (SELECT MAX(payment_date) FROM payment WHERE id_order = o.id_order), NULL),
                            103)                                     AS payment_date,
       SUM(ohp.vat_price)                                            AS vat_amount,
       SUM(ohp.tf_price)                                             AS tf_amount
FROM [order] o
         INNER JOIN customer c ON o.id_customer = c.id_customer
         INNER JOIN address b ON o.id_billing_address = b.id_address
         INNER JOIN address d ON o.id_delivery_address = d.id_address
         INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order
WHERE o.deleted = 0
GROUP BY o.id_order,
         o.reference,
         o.issue_date,
         o.expected_delivery_date,
         c.last_name,
         c.first_name,
         c.birthdate,
         b.street,
         b.zip_code,
         b.city,
         d.street,
         d.zip_code,
         d.city;

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

