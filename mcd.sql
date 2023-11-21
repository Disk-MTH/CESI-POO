IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'database')
BEGIN
        CREATE DATABASE [database];
END
GO;

USE [database];
GO;

CREATE TABLE customer
(
    id_customer INT IDENTITY (1,1) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    birthdate DATE NOT NULL,
    PRIMARY KEY(id_customer)
);
GO;

CREATE TABLE staff
(
    id_staff INT IDENTITY (1,1) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    hire_date DATE NOT NULL,
    PRIMARY KEY(id_staff)
);
GO;

CREATE TABLE product
(
    id_product INT IDENTITY (1,1) NOT NULL,
    reference VARCHAR(50) NOT NULL,
    name VARCHAR(50) NOT NULL,
    vat_rate REAL NOT NULL,
    provisioning_threshold SMALLINT NOT NULL,
    PRIMARY KEY(id_product)
);
GO;

CREATE TABLE stock
(
    id_stock INT IDENTITY (1,1) NOT NULL,
    stock_date DATETIME NOT NULL,
    quantity SMALLINT NOT NULL,
    quantity_left SMALLINT NOT NULL,
    id_product INT NOT NULL,
    PRIMARY KEY(id_stock),
    FOREIGN KEY(id_product) REFERENCES product(id_product)
);
GO;

CREATE TABLE [order]
(
    id_order INT IDENTITY (1,1) NOT NULL,
    reference VARCHAR(50) NOT NULL,
    issue_date VARCHAR(50) NOT NULL,
    expected_delivery_date VARCHAR(50) NOT NULL,
    PRIMARY KEY(id_order)
);
GO;

CREATE TABLE city
(
    id_city INT IDENTITY (1,1) NOT NULL,
    name VARCHAR(50) NOT NULL,
    PRIMARY KEY(id_city)
);
GO;

CREATE TABLE payment
(
    id_payment INT IDENTITY (1,1) NOT NULL,
    payment_date DATETIME NOT NULL,
    amount REAL,
    id_order INT NOT NULL,
    PRIMARY KEY(id_payment),
    FOREIGN KEY(id_order) REFERENCES [order](id_order)
);
GO;

CREATE TABLE payment_mean
(
    id_payment_mean INT IDENTITY (1,1) NOT NULL,
    type VARCHAR(50) NOT NULL,
    PRIMARY KEY(id_payment_mean)
);
GO;

CREATE TABLE address
(
    id_address INT IDENTITY (1,1) NOT NULL,
    street_name VARCHAR(50) NOT NULL,
    id_city INT NOT NULL,
    PRIMARY KEY(id_address),
    FOREIGN KEY(id_city) REFERENCES city(id_city)
);
GO;

CREATE TABLE orderHasProducts
(
     id_product INT,
     id_order INT,
     quantity SMALLINT,
     tf_price REAL NOT NULL,
     vat_price REAL NOT NULL,
     price REAL NOT NULL,
     price_after_discounts REAL NOT NULL,
     PRIMARY KEY(id_product, id_order),
     FOREIGN KEY(id_product) REFERENCES product(id_product),
     FOREIGN KEY(id_order) REFERENCES [order](id_order)
);
GO;

CREATE TABLE orderHasStaffs
(
    id_staff INT,
    id_order INT,
    PRIMARY KEY(id_staff, id_order),
    FOREIGN KEY(id_staff) REFERENCES staff(id_staff),
    FOREIGN KEY(id_order) REFERENCES [order](id_order)
);
GO;

CREATE TABLE orderHasClients
(
    id_customer INT,
    id_order INT,
    PRIMARY KEY(id_customer, id_order),
    FOREIGN KEY(id_customer) REFERENCES customer(id_customer),
    FOREIGN KEY(id_order) REFERENCES [order](id_order)
);
GO;

CREATE TABLE billingAddresses
(
    id_address INT,
    id_customer INT,
    PRIMARY KEY(id_address, id_customer),
    FOREIGN KEY(id_address) REFERENCES address(id_address),
    FOREIGN KEY(id_customer) REFERENCES customer(id_customer)
);
GO;

CREATE TABLE deliveryAddresses
(
    id_address INT,
    id_customer INT,
    PRIMARY KEY(id_address, id_customer),
    FOREIGN KEY(id_address) REFERENCES address(id_address),
    FOREIGN KEY(id_customer) REFERENCES customer(id_customer)
);
GO;

CREATE TABLE paymentHasPaymentMeans
(
    id_payment INT,
    id_payment_mean INT,
    PRIMARY KEY(id_payment, id_payment_mean),
    FOREIGN KEY(id_payment) REFERENCES payment(id_payment),
    FOREIGN KEY(id_payment_mean) REFERENCES payment_mean(id_payment_mean)
);
GO;

CREATE TABLE staffHasAddresses
(
    id_address INT,
    id_staff INT,
    PRIMARY KEY(id_address, id_staff),
    FOREIGN KEY(id_address) REFERENCES address(id_address),
    FOREIGN KEY(id_staff) REFERENCES staff(id_staff)
);
GO;

CREATE TABLE staffHasBoss
(
    id_staff INT,
    id_staff_1 INT,
    PRIMARY KEY(id_staff, id_staff_1),
    FOREIGN KEY(id_staff) REFERENCES staff(id_staff),
    FOREIGN KEY(id_staff_1) REFERENCES staff(id_staff)
);
GO;
