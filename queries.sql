USE [database];
GO;

/* ------------------------- Customer -------------------------*/

/* Query to fill CustomerPage */
SELECT id_customer,
       first_name,
       last_name,
       CONVERT(VARCHAR(10), birthdate, 103) AS birthdate
FROM customer;
/*
WHERE deleted = 0;*/

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
/*should delete user delete addresses of user ?*/

/* ------------------------- Addresses -------------------------*/

/* Query to get addresses from a client */
SELECT a.id_address,
       a.street,
       a.zip_code,
       a.city,
       at.type
FROM address a
         INNER JOIN customerHasAddresses cha ON a.id_address = cha.id_address
         INNER JOIN address_type at ON cha.id_address_type = at.id_address_type
WHERE a.deleted = 0
  AND cha.id_customer = 1;

/* Query to insert new address */
INSERT INTO address (street, zip_code, city)
VALUES ('aa', 'bb', 'cc');

INSERT INTO customerHasAddresses (id_customer, id_address, id_address_type)
VALUES (1, 1, 1);

/* Query to update an address */
UPDATE address
SET deleted = 1
WHERE id_address = 1; /* Then insert new*/



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