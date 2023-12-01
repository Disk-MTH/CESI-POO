USE [database];
GO;

/* Query to fill CustomerPage */
SELECT c.id_customer,
       c.first_name,
       c.last_name,
       CONVERT(VARCHAR, c.birthdate, 103)                                       AS birthdate,
       ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount
FROM customer c
         LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount
                    FROM customerHasAddresses cha
                    WHERE cha.type = 0
                    GROUP BY id_customer) b ON c.id_customer = b.id_customer
         LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount
                    FROM customerHasAddresses cha
                    WHERE cha.type = 1
                    GROUP BY id_customer) d ON c.id_customer = d.id_customer; /*WHERE c.deleted = 0;*/

/* Query to insert new customer */
INSERT INTO customer (first_name, last_name, birthdate)
VALUES ('aa', 'bb', 'cc');

/* Query to update a customer */
UPDATE customer
SET first_name = 'aa',
    last_name = 'bb',
    birthdate = 'cc'
WHERE id_customer = 1;

/* Query to delete user (set "deleted" to 1) */
UPDATE customer SET deleted = 1 WHERE id_customer = 1;

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

/* Query to get addresses from a client showing the type of address */

SELECT a.id_address,
       a.street_name,
       a.zip_code,
       cha.type,
       a.city
FROM address a JOIN customerHasAddresses cha ON a.id_address = cha.id_address
WHERE cha.id_customer = 2;

/* Query to create a new address and set it as a customer's address */
INSERT INTO address (street_name, zip_code, city)
VALUES ('aa', 28453, 'cc');

INSERT INTO customerHasAddresses (id_customer, id_address, type)
VALUES (2, 1, 0);

/* Query to update an address */
UPDATE address
SET street_name = 'aa',
    zip_code = 'bb',
    city = 'cc'
WHERE id_address = 1;

INSERT INTO address (street_name, zip_code, city) VALUES ('sdf3', '44444', 'czfa')

INSERT INTO customerHasAddresses (id_customer, id_address, type) VALUES ('3', '1011', '1');


