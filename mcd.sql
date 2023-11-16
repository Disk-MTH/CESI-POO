/*------------------------------------------------------------
*        Script SQLSERVER 
------------------------------------------------------------*/

IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'database')
BEGIN
        CREATE DATABASE [database];
END
GO;

USE [database];
GO;

IF NOT EXISTS (SELECT * FROM sys.schemas WHERE name = 'data')
BEGIN
EXEC('CREATE SCHEMA [data]');
END
GO;

/*------------------------------------------------------------
-- Table: article
------------------------------------------------------------*/
CREATE TABLE [data].[article](
                                 id               INT IDENTITY (1,1) NOT NULL ,
    nom              VARCHAR (50) NOT NULL ,
    type_article     VARCHAR (50) NOT NULL ,
    tva_rate         REAL  NOT NULL ,
    quantite_stock   INT  NOT NULL ,
    seuil_reapro     INT  NOT NULL ,
    supprimer        bit  NOT NULL  ,
    CONSTRAINT article_PK PRIMARY KEY (id)
    );
GO;

/*------------------------------------------------------------
-- Table: client
------------------------------------------------------------*/
CREATE TABLE [data].[client](
                                id                   INT IDENTITY (1,1) NOT NULL ,
    nom                  VARCHAR (50) NOT NULL ,
    prenom               VARCHAR (50) NOT NULL ,
    date_naissance       VARCHAR (50) NOT NULL ,
    date_premier_achat   VARCHAR (50) NOT NULL ,
    supprimer            bit  NOT NULL  ,
    CONSTRAINT client_PK PRIMARY KEY (id)
    );
GO;

/*------------------------------------------------------------
-- Table: commande
------------------------------------------------------------*/
CREATE TABLE [data].[commande](
                                  id                                   INT IDENTITY (1,1) NOT NULL ,
    reference                            VARCHAR (50) NOT NULL ,
    date_livraison                       VARCHAR (50) NOT NULL ,
    date_emission                        VARCHAR (50) NOT NULL ,
    date_de_solde                        VARCHAR (50) NOT NULL ,
    total_ht                             REAL  NOT NULL ,
    total_ttc                            REAL  NOT NULL ,
    supprimer                            bit  NOT NULL ,
    id_client                            INT  NOT NULL ,
    id_adresse_cmd_adresse_livraison     INT  NOT NULL ,
    id_adresse_cmd_adresse_facturation   INT  NOT NULL ,
    id_client_commander                  INT  NOT NULL  ,
    CONSTRAINT commande_PK PRIMARY KEY (id) ,
    CONSTRAINT commande_AK UNIQUE (id_client,id_adresse_cmd_adresse_livraison,id_adresse_cmd_adresse_facturation)

    ,CONSTRAINT commande_client_FK FOREIGN KEY (id_client_commander) REFERENCES [data].[client](id)
    );
GO;

/*------------------------------------------------------------
-- Table: commande_article
------------------------------------------------------------*/
CREATE TABLE [data].[commande_article](
                                          id                       INT IDENTITY (1,1) NOT NULL ,
    quantite                 INT  NOT NULL ,
    prix_unitaire_ht         REAL  NOT NULL ,
    remise                   INT  NOT NULL ,
    supprimer                bit  NOT NULL ,
    id_article               INT  NOT NULL ,
    id_commande              INT  NOT NULL ,
    id_article_Avoir         INT  NOT NULL ,
    id_commande_Appartenir   INT  NOT NULL  ,
    CONSTRAINT commande_article_PK PRIMARY KEY (id) ,
    CONSTRAINT commande_article_AK UNIQUE (id_article,id_commande)

    ,CONSTRAINT commande_article_article_FK FOREIGN KEY (id_article_Avoir) REFERENCES [data].[article](id)
    ,CONSTRAINT commande_article_commande0_FK FOREIGN KEY (id_commande_Appartenir) REFERENCES [data].[commande](id)
    );
GO;

/*------------------------------------------------------------
-- Table: paiement
------------------------------------------------------------*/
CREATE TABLE [data].[paiement](
                                  id                     INT IDENTITY (1,1) NOT NULL ,
    date                   VARCHAR (50) NOT NULL ,
    moyen                  VARCHAR (50) NOT NULL ,
    montant                INT  NOT NULL ,
    id_commande            INT  NOT NULL ,
    id_commande_Composer   INT  NOT NULL  ,
    CONSTRAINT paiement_PK PRIMARY KEY (id) ,
    CONSTRAINT paiement_AK UNIQUE (id_commande)

    ,CONSTRAINT paiement_commande_FK FOREIGN KEY (id_commande_Composer) REFERENCES [data].[commande](id)
    );
GO;

/*------------------------------------------------------------
-- Table: palier_remise
------------------------------------------------------------*/
CREATE TABLE [data].[palier_remise](
                                       id                  INT IDENTITY (1,1) NOT NULL ,
    q_mini              INT  NOT NULL ,
    p_u_ht              REAL  NOT NULL ,
    supprimer           bit  NOT NULL ,
    id_article          INT  NOT NULL ,
    id_article_remise   INT  NOT NULL  ,
    CONSTRAINT palier_remise_PK PRIMARY KEY (id) ,
    CONSTRAINT palier_remise_AK UNIQUE (id_article)

    ,CONSTRAINT palier_remise_article_FK FOREIGN KEY (id_article_remise) REFERENCES [data].[article](id)
    );
GO;

/*------------------------------------------------------------
-- Table: personnel
------------------------------------------------------------*/
CREATE TABLE [data].[personnel](
                                   id             INT IDENTITY (1,1) NOT NULL ,
    nom            VARCHAR (50) NOT NULL ,
    prenom         VARCHAR (50) NOT NULL ,
    de             VARCHAR (50) NOT NULL ,
    supprimer      bit  NOT NULL ,
    id_adresse     INT  NOT NULL ,
    id_personnel   INT  NOT NULL  ,
    CONSTRAINT personnel_PK PRIMARY KEY (id) ,
    CONSTRAINT personnel_AK UNIQUE (id_adresse,id_personnel)
    );
GO;

/*------------------------------------------------------------
-- Table: adresse_livraison
------------------------------------------------------------*/
CREATE TABLE [data].[adresse_livraison](
                                           id           INT IDENTITY (1,1) NOT NULL ,
    supprimer    bit  NOT NULL ,
    id_adresse   INT  NOT NULL ,
    id_client    INT  NOT NULL  ,
    CONSTRAINT adresse_livraison_PK PRIMARY KEY (id) ,
    CONSTRAINT adresse_livraison_AK UNIQUE (id_adresse,id_client)
    );
GO;

/*------------------------------------------------------------
-- Table: adresse_facturation
------------------------------------------------------------*/
CREATE TABLE [data].[adresse_facturation](
                                             id           INT IDENTITY (1,1) NOT NULL ,
    supprimer    bit  NOT NULL ,
    id_adresse   INT  NOT NULL ,
    id_client    INT  NOT NULL  ,
    CONSTRAINT adresse_facturation_PK PRIMARY KEY (id) ,
    CONSTRAINT adresse_facturation_AK UNIQUE (id_adresse,id_client)
    );
GO;

/*------------------------------------------------------------
-- Table: adresse
------------------------------------------------------------*/
CREATE TABLE [data].[adresse](
                                 id                       INT IDENTITY (1,1) NOT NULL ,
    ligne1                   VARCHAR (50) NOT NULL ,
    pays                     VARCHAR (50) NOT NULL ,
    ville                    VARCHAR (50) NOT NULL ,
    cp                       VARCHAR (50) NOT NULL ,
    id_personnel             INT  NOT NULL ,
    id_adresse_livraison     INT  NOT NULL ,
    id_adresse_facturation   INT  NOT NULL  ,
    CONSTRAINT adresse_PK PRIMARY KEY (id)

    ,CONSTRAINT adresse_personnel_FK FOREIGN KEY (id_personnel) REFERENCES [data].[personnel](id)
    ,CONSTRAINT adresse_adresse_livraison0_FK FOREIGN KEY (id_adresse_livraison) REFERENCES [data].[adresse_livraison](id)
    ,CONSTRAINT adresse_adresse_facturation1_FK FOREIGN KEY (id_adresse_facturation) REFERENCES [data].[adresse_facturation](id)
    );
GO;

/*------------------------------------------------------------
-- Table: relation2
------------------------------------------------------------*/
CREATE TABLE [data].[relation2](
                                   id          INT  NOT NULL ,
                                   id_client   INT  NOT NULL  ,
                                   CONSTRAINT relation2_PK PRIMARY KEY (id,id_client)

    ,CONSTRAINT relation2_adresse_livraison_FK FOREIGN KEY (id) REFERENCES [data].[adresse_livraison](id)
    ,CONSTRAINT relation2_client0_FK FOREIGN KEY (id_client) REFERENCES [data].[client](id)
    );
GO;

/*------------------------------------------------------------
-- Table: relation3
------------------------------------------------------------*/
CREATE TABLE [data].[relation3](
                                   id          INT  NOT NULL ,
                                   id_client   INT  NOT NULL  ,
                                   CONSTRAINT relation3_PK PRIMARY KEY (id,id_client)

    ,CONSTRAINT relation3_adresse_facturation_FK FOREIGN KEY (id) REFERENCES [data].[adresse_facturation](id)
    ,CONSTRAINT relation3_client0_FK FOREIGN KEY (id_client) REFERENCES [data].[client](id)
    );
GO;