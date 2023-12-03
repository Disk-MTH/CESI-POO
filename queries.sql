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
DELETE FROM customer
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
         INNER JOIN customerHasAddresse cha ON a.id_address = cha.id_address
         INNER JOIN address_type at ON cha.id_address_type = at.id_address_type
WHERE a.deleted = 0
  AND cha.id_customer = 1;

/* Query to insert new address */
INSERT INTO address (street, zip_code, city)
VALUES ('aa', 'bb', 'cc');

INSERT INTO customerHasAddresse (id_customer, id_address, id_address_type)
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