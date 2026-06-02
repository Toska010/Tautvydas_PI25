-- Duomenu bazes strukturos sukurimas, ismetamos lenteles jei sutampa pavadinimas ir sukuriamos naujos, zemiau aprasytos lenteles ir rysiai
-- IMPORTANT: DROP TABLES (order matters because of foreign keys)
-- =========================================
-- DROP TABLES (ORDER MATTERS)
-- =========================================
DROP TABLE IF EXISTS Uzklausos;
DROP TABLE IF EXISTS Mokejimai;
DROP TABLE IF EXISTS PersonaloAtsiliepimai;
DROP TABLE IF EXISTS KambariuAtsiliepimai;
DROP TABLE IF EXISTS PastatuAtsiliepimai;
DROP TABLE IF EXISTS UzklausuBusenos;
DROP TABLE IF EXISTS MokejimuBusenos;
DROP TABLE IF EXISTS Ivertinimai;
DROP TABLE IF EXISTS Administratoriai;
DROP TABLE IF EXISTS Personalas;
DROP TABLE IF EXISTS Apgyvendinimas;
DROP TABLE IF EXISTS Kambariai;
DROP TABLE IF EXISTS PastatuKainodara;
DROP TABLE IF EXISTS KainodarosTipai;
DROP TABLE IF EXISTS KainosGrupe;
DROP TABLE IF EXISTS Pastatai;
DROP TABLE IF EXISTS Institucijos;
DROP TABLE IF EXISTS AdministratoriausLygmuo;
DROP TABLE IF EXISTS PersonaloPareigos;
DROP TABLE IF EXISTS Vartotojai;
DROP TABLE IF EXISTS VartotojuTipai;
DROP TABLE IF EXISTS KainosGrupe;

-- =========================================
-- CORE TABLES
-- =========================================

CREATE TABLE VartotojuTipai (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(255)
);

CREATE TABLE Vartotojai (
    ID INT PRIMARY KEY,
    Vardas VARCHAR(255),
    Pavarde VARCHAR(255),
    Telefonas VARCHAR(50),
    ElPastas VARCHAR(255),
    VartotojoTipas INT NOT NULL,
    FOREIGN KEY (VartotojoTipas) REFERENCES VartotojuTipai(ID)
);

CREATE TABLE PersonaloPareigos (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(255)
);

CREATE TABLE AdministratoriausLygmuo (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(255)
);

CREATE TABLE Institucijos (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(255)
);

CREATE TABLE Pastatai (
    ID INT PRIMARY KEY,
    Institucija INT NOT NULL,
    Adresas VARCHAR(255),
    FOREIGN KEY (Institucija) REFERENCES Institucijos(ID)
);

CREATE TABLE Kambariai (
    ID INT PRIMARY KEY,
    Pastatas INT NOT NULL,
    KambarioNumeris VARCHAR(50),
    FOREIGN KEY (Pastatas) REFERENCES Pastatai(ID)
);

CREATE TABLE Apgyvendinimas (
    ID INT PRIMARY KEY,
    Studentas INT NOT NULL,
    Kambarys INT NOT NULL,
    PradziosData DATE,
    PabaigosData DATE,
    FOREIGN KEY (Studentas) REFERENCES Vartotojai(ID),
    FOREIGN KEY (Kambarys) REFERENCES Kambariai(ID)
);

CREATE TABLE Personalas (
    ID INT PRIMARY KEY,
    Vartotojas INT NOT NULL,
    Institucija INT NOT NULL,
    Pareigos INT NOT NULL,
    FOREIGN KEY (Vartotojas) REFERENCES Vartotojai(ID),
    FOREIGN KEY (Institucija) REFERENCES Institucijos(ID),
    FOREIGN KEY (Pareigos) REFERENCES PersonaloPareigos(ID)
);

CREATE TABLE Administratoriai (
    ID INT PRIMARY KEY,
    Vartotojas INT NOT NULL,
    PrieigosLygis INT NOT NULL,
    FOREIGN KEY (Vartotojas) REFERENCES Vartotojai(ID),
    FOREIGN KEY (PrieigosLygis) REFERENCES AdministratoriausLygmuo(ID)
);

-- =========================================
-- LOOKUP TABLES
-- =========================================

CREATE TABLE Ivertinimai (
    ID INT PRIMARY KEY,
    Ivertinimas INT
);

CREATE TABLE MokejimuBusenos (
    ID INT PRIMARY KEY,
    Busena VARCHAR(100)
);

CREATE TABLE UzklausuBusenos (
    ID INT PRIMARY KEY,
    Busena VARCHAR(100)
);

-- ✅ NEW: pricing groups (student categories)
CREATE TABLE KainosGrupe (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(100)
);

-- ✅ room type definitions (rows in your table)
CREATE TABLE KainodarosTipai (
    ID INT PRIMARY KEY,
    Pavadinimas VARCHAR(255)
);

-- ✅ FINAL pricing table (correct normalized form)
CREATE TABLE PastatuKainodara (
    ID INT PRIMARY KEY,
    Pastatas INT NOT NULL,
    KainodarosTipas INT NOT NULL,
    KainosGrupe INT NOT NULL,
    Kaina DECIMAL(10,2),
    FOREIGN KEY (Pastatas) REFERENCES Pastatai(ID),
    FOREIGN KEY (KainodarosTipas) REFERENCES KainodarosTipai(ID),
    FOREIGN KEY (KainosGrupe) REFERENCES KainosGrupe(ID)
);

-- =========================================
-- REVIEWS
-- =========================================

CREATE TABLE PastatuAtsiliepimai (
    ID INT PRIMARY KEY,
    Apgyvendinimas INT NOT NULL,
    Ivertinimas INT NOT NULL,
    Komentaras VARCHAR(500),
    Sukurta DATETIME,
    FOREIGN KEY (Apgyvendinimas) REFERENCES Apgyvendinimas(ID),
    FOREIGN KEY (Ivertinimas) REFERENCES Ivertinimai(ID)
);

CREATE TABLE KambariuAtsiliepimai (
    ID INT PRIMARY KEY,
    Apgyvendinimas INT NOT NULL,
    Ivertinimas INT NOT NULL,
    Komentaras VARCHAR(500),
    Sukurta DATETIME,
    FOREIGN KEY (Apgyvendinimas) REFERENCES Apgyvendinimas(ID),
    FOREIGN KEY (Ivertinimas) REFERENCES Ivertinimai(ID)
);

CREATE TABLE PersonaloAtsiliepimai (
    ID INT PRIMARY KEY,
    Apgyvendinimas INT NOT NULL,
    Personalas INT NOT NULL,
    Ivertinimas INT NOT NULL,
    Komentaras VARCHAR(500),
    Sukurta DATETIME,
    FOREIGN KEY (Apgyvendinimas) REFERENCES Apgyvendinimas(ID),
    FOREIGN KEY (Personalas) REFERENCES Personalas(ID),
    FOREIGN KEY (Ivertinimas) REFERENCES Ivertinimai(ID)
);

-- =========================================
-- PAYMENTS & REQUESTS
-- =========================================

CREATE TABLE Mokejimai (
    ID INT PRIMARY KEY,
    Apgyvendinimas INT NOT NULL,
    Busena INT NOT NULL,
    Suma DECIMAL(10,2),
    MokejimoData DATE,
    FOREIGN KEY (Apgyvendinimas) REFERENCES Apgyvendinimas(ID),
    FOREIGN KEY (Busena) REFERENCES MokejimuBusenos(ID)
);

CREATE TABLE Uzklausos (
    ID INT PRIMARY KEY,
    Apgyvendinimas INT NOT NULL,
    PriskirtasPersonalas INT,
    Busena INT NOT NULL,
    Aprasymas VARCHAR(500),
    Sukurta DATETIME,
    FOREIGN KEY (Apgyvendinimas) REFERENCES Apgyvendinimas(ID),
    FOREIGN KEY (PriskirtasPersonalas) REFERENCES Personalas(ID),
    FOREIGN KEY (Busena) REFERENCES UzklausuBusenos(ID)
);