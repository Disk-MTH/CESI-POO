USE [database];
GO;

/* Query to fill CustomerPage */
/* add the count of addresseswhere deleted = 0  in the column "addressesCount" */
SELECT c.id_customer,
       c.first_name,
       c.last_name,
       CONVERT(VARCHAR, c.birthdate, 103)                                                            AS birthdate,
       (SELECT COUNT(*) FROM customerHasAddresses WHERE id_customer = c.id_customer AND deleted = 0) AS addressesCount
FROM customer c/*;
WHERE c.deleted = 0;*/

/* Query to insert new customer */
INSERT INTO customer (first_name, last_name, birthdate)
VALUES ('aa', 'bb', 'cc');

/* Query to update a customer */
UPDATE customer
SET first_name = 'aa',
    last_name  = 'bb',
    birthdate  = 'cc'
WHERE id_customer = 1;

/* Query to delete user (set "deleted" to 1) */
UPDATE customer
SET deleted = 1
WHERE id_customer = 1;

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

/* Query to get addresses from a client */
SELECT a.id_address,
       a.street,
       a.zip_code,
       a.city,
       at.type
FROM address a
         INNER JOIN customerHasAddresses cha ON a.id_address = cha.id_address
         INNER JOIN address_type at ON cha.id_address_type = at.id_address_type
WHERE cha.id_customer = 1;

SELECT a.id_address, a.street, a.zip_code, a.city, at.type
FROM address a
         INNER JOIN customerHasAddresses cha ON a.id_address = cha.id_address
         INNER JOIN address_type at ON cha.id_address_type = at.id_address_type
WHERE cha.id_customer = 1;