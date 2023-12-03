IF NOT EXISTS (SELECT *
               FROM sys.databases
               WHERE name = 'database')
    BEGIN
        CREATE DATABASE [database];
    END
GO;

USE [database];
GO;

CREATE TABLE address
(
    id_address INT IDENTITY (1,1) NOT NULL,
    street     VARCHAR(50)        NOT NULL,
    city       VARCHAR(50)        NOT NULL,
    zip_code   INT                NOT NULL,
    deleted    BIT                NOT NULL DEFAULT 0,
    PRIMARY KEY (id_address)
);
GO;

CREATE TABLE address_type
(
    id_address_type INT IDENTITY (1,1) NOT NULL,
    type            VARCHAR(100)       NOT NULL,
    PRIMARY KEY (id_address_type)
);
GO;

CREATE TABLE customer
(
    id_customer INT IDENTITY (1,1) NOT NULL,
    first_name  VARCHAR(50)        NOT NULL,
    last_name   VARCHAR(50)        NOT NULL,
    birthdate   DATE               NOT NULL,
    deleted     BIT             NOT NULL DEFAULT 0,
    PRIMARY KEY (id_customer)
);
GO;

CREATE TABLE staff
(
    id_staff   INT IDENTITY (1,1) NOT NULL,
    first_name VARCHAR(50)        NOT NULL,
    last_name  VARCHAR(50)        NOT NULL,
    hire_date  DATE               NOT NULL,
    deleted    BIT             NOT NULL DEFAULT 0,
    id_staff_1 INT,
    id_address INT                NOT NULL,
    PRIMARY KEY (id_staff),
    UNIQUE (id_address),
    FOREIGN KEY (id_staff_1) REFERENCES staff (id_staff),
    FOREIGN KEY (id_address) REFERENCES address (id_address)
);
GO;

CREATE TABLE product
(
    id_product             INT IDENTITY (1,1) NOT NULL,
    reference              VARCHAR(50)        NOT NULL,
    name                   VARCHAR(50)        NOT NULL,
    vat_rate               REAL               NOT NULL,
    provisioning_threshold INT                NOT NULL,
    deleted                BIT             NOT NULL DEFAULT 0,
    quantity               INT                NOT NULL,
    buy_price              REAL               NOT NULL,
    colour                 VARCHAR(50)        NOT NULL,
    type                   VARCHAR(50)        NOT NULL,
    PRIMARY KEY (id_product)
);
GO;

CREATE TABLE [order]
(
    id_order               INT IDENTITY (1,1) NOT NULL,
    reference              VARCHAR(50)        NOT NULL,
    issue_date             VARCHAR(50)        NOT NULL,
    expected_delivery_date VARCHAR(50)        NOT NULL,
    deleted                BIT             NOT NULL DEFAULT 0,
    id_address             INT                NOT NULL,
    id_address_1           INT                NOT NULL,
    id_customer            INT                NOT NULL,
    PRIMARY KEY (id_order),
    FOREIGN KEY (id_address) REFERENCES address (id_address),
    FOREIGN KEY (id_address_1) REFERENCES address (id_address),
    FOREIGN KEY (id_customer) REFERENCES customer (id_customer)
);
GO;

CREATE TABLE payment
(
    id_payment   INT IDENTITY (1,1) NOT NULL,
    payment_date DATETIME           NOT NULL,
    payment_mean SMALLINT           NOT NULL,
    amount       REAL               NOT NULL,
    validated    BIT             NOT NULL DEFAULT 0,
    deleted      BIT             NOT NULL DEFAULT 0,
    id_order     INT                NOT NULL,
    PRIMARY KEY (id_payment),
    FOREIGN KEY (id_order) REFERENCES [order] (id_order)
);
GO;

CREATE TABLE tiered_price
(
    id_tiered_price  INT IDENTITY (1,1) NOT NULL,
    minimal_quantity INT                NOT NULL,
    tf_price         REAL               NOT NULL,
    deleted          BIT             NOT NULL DEFAULT 0,
    id_product       INT                NOT NULL,
    PRIMARY KEY (id_tiered_price),
    FOREIGN KEY (id_product) REFERENCES product (id_product)
);
GO;

CREATE TABLE suggestion
(
    id_suggestion INT IDENTITY (1,1) NOT NULL,
    zip_code      INT                NOT NULL,
    city          VARCHAR(50)        NOT NULL,
    PRIMARY KEY (id_suggestion)
);
GO;

CREATE TABLE orderHasProducts
(
    id_product INT,
    id_order   INT,
    quantity   INT,
    tf_price   REAL NOT NULL,
    vat_price  REAL NOT NULL,
    price      REAL NOT NULL,
    PRIMARY KEY (id_product, id_order),
    FOREIGN KEY (id_product) REFERENCES product (id_product),
    FOREIGN KEY (id_order) REFERENCES [order] (id_order)
);
GO;

CREATE TABLE customerHasAddresses
(
    id_address      INT,
    id_customer     INT,
    id_address_type INT,
    PRIMARY KEY (id_address, id_customer, id_address_type),
    FOREIGN KEY (id_address) REFERENCES address (id_address),
    FOREIGN KEY (id_customer) REFERENCES customer (id_customer),
    FOREIGN KEY (id_address_type) REFERENCES address_type (id_address_type)
);
GO;