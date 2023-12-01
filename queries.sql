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
                    GROUP BY id_customer) d ON c.id_customer = d.id_customer;

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

SELECT id_product, deleted, reference, type, name, colour, buy_price, vat_rate, quantity, provisioning_threshold FROM product;