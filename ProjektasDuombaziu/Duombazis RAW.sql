CREATE TABLE `VartotojuTipai` (
  `ID` int PRIMARY KEY,
  `Pavadinimas` varchar(255)
);

CREATE TABLE `Vartotojai` (
  `ID` int PRIMARY KEY,
  `Vardas` varchar(255),
  `Pavarde` varchar(255),
  `Telefonas` varchar(255),
  `ElPastas` varchar(255),
  `VartotojoTipasID` int NOT NULL
);

CREATE TABLE `PersonaloPareigos` (
  `ID` int PRIMARY KEY,
  `Pavadinimas` varchar(255)
);

CREATE TABLE `AdministratoriausLygmuo` (
  `ID` int PRIMARY KEY,
  `Pavadinimas` varchar(255)
);

CREATE TABLE `Institucijos` (
  `ID` int PRIMARY KEY,
  `Pavadinimas` varchar(255)
);

CREATE TABLE `Pastatai` (
  `ID` int PRIMARY KEY,
  `Institucija` int NOT NULL,
  `Adresas` varchar(255)
);

CREATE TABLE `KambariuDydziai` (
  `ID` int PRIMARY KEY,
  `Dydis` int
);

CREATE TABLE `KambariuKainodara` (
  `ID` int PRIMARY KEY,
  `Dydis` int NOT NULL,
  `Talpa` int,
  `Kaina` decimal
);

CREATE TABLE `Kambariai` (
  `ID` int PRIMARY KEY,
  `Pastatas` int NOT NULL,
  `Kainodara` int NOT NULL,
  `KambarioNumeris` varchar(255)
);

CREATE TABLE `Apgyvendinimas` (
  `ID` int PRIMARY KEY,
  `Studentas` int NOT NULL,
  `Kambarys` int NOT NULL,
  `PradziosData` date,
  `PabaigosData` date
);

CREATE TABLE `Personalas` (
  `ID` int PRIMARY KEY,
  `Vartotojas` int NOT NULL,
  `Institucija` int NOT NULL,
  `Pareigos` int NOT NULL
);

CREATE TABLE `Administratoriai` (
  `ID` int PRIMARY KEY,
  `Vartotojas` int NOT NULL,
  `PrieigosLygis` int NOT NULL
);

CREATE TABLE `Ivertinimai` (
  `ID` int PRIMARY KEY,
  `Ivertinimas` int
);

CREATE TABLE `MokejimuBusenos` (
  `ID` int PRIMARY KEY,
  `Busena` varchar(255)
);

CREATE TABLE `UzklausuBusenos` (
  `ID` int PRIMARY KEY,
  `Pavadinimas` varchar(255)
);

CREATE TABLE `PastatuAtsiliepimai` (
  `ID` int PRIMARY KEY,
  `Apgyvendinimas` int NOT NULL,
  `Ivertinimas` int NOT NULL,
  `Komentaras` varchar(255),
  `Sukurta` datetime
);

CREATE TABLE `KambariuAtsiliepimai` (
  `ID` int PRIMARY KEY,
  `Apgyvendinimas` int NOT NULL,
  `Ivertinimas` int NOT NULL,
  `Komentaras` varchar(255),
  `Sukurta` datetime
);

CREATE TABLE `PersonaloAtsiliepimai` (
  `ID` int PRIMARY KEY,
  `Apgyvendinimas` int NOT NULL,
  `Personalas` int NOT NULL,
  `Ivertinimas` int NOT NULL,
  `Komentaras` varchar(255),
  `Sukurta` datetime
);

CREATE TABLE `Mokejimai` (
  `ID` int PRIMARY KEY,
  `ApgyvendinimasID` int NOT NULL,
  `BusenaID` int NOT NULL,
  `Suma` decimal,
  `MokejimoData` date
);

CREATE TABLE `Uzklausos` (
  `ID` int PRIMARY KEY,
  `Apgyvendinimas` int NOT NULL,
  `PriskirtasPersonalas` int,
  `Busena` int NOT NULL,
  `Aprasymas` varchar(255),
  `Sukurta` datetime
);

ALTER TABLE `Vartotojai` ADD FOREIGN KEY (`VartotojoTipasID`) REFERENCES `VartotojuTipai` (`ID`);

ALTER TABLE `Pastatai` ADD FOREIGN KEY (`Institucija`) REFERENCES `Institucijos` (`ID`);

ALTER TABLE `KambariuKainodara` ADD FOREIGN KEY (`Dydis`) REFERENCES `KambariuDydziai` (`ID`);

ALTER TABLE `Kambariai` ADD FOREIGN KEY (`Pastatas`) REFERENCES `Pastatai` (`ID`);

ALTER TABLE `Kambariai` ADD FOREIGN KEY (`Kainodara`) REFERENCES `KambariuKainodara` (`ID`);

ALTER TABLE `Apgyvendinimas` ADD FOREIGN KEY (`Studentas`) REFERENCES `Vartotojai` (`ID`);

ALTER TABLE `Apgyvendinimas` ADD FOREIGN KEY (`Kambarys`) REFERENCES `Kambariai` (`ID`);

ALTER TABLE `Personalas` ADD FOREIGN KEY (`Vartotojas`) REFERENCES `Vartotojai` (`ID`);

ALTER TABLE `Personalas` ADD FOREIGN KEY (`Institucija`) REFERENCES `Institucijos` (`ID`);

ALTER TABLE `Personalas` ADD FOREIGN KEY (`Pareigos`) REFERENCES `PersonaloPareigos` (`ID`);

ALTER TABLE `Administratoriai` ADD FOREIGN KEY (`Vartotojas`) REFERENCES `Vartotojai` (`ID`);

ALTER TABLE `Administratoriai` ADD FOREIGN KEY (`PrieigosLygis`) REFERENCES `AdministratoriausLygmuo` (`ID`);

ALTER TABLE `PastatuAtsiliepimai` ADD FOREIGN KEY (`Apgyvendinimas`) REFERENCES `Apgyvendinimas` (`ID`);

ALTER TABLE `PastatuAtsiliepimai` ADD FOREIGN KEY (`Ivertinimas`) REFERENCES `Ivertinimai` (`ID`);

ALTER TABLE `KambariuAtsiliepimai` ADD FOREIGN KEY (`Apgyvendinimas`) REFERENCES `Apgyvendinimas` (`ID`);

ALTER TABLE `KambariuAtsiliepimai` ADD FOREIGN KEY (`Ivertinimas`) REFERENCES `Ivertinimai` (`ID`);

ALTER TABLE `PersonaloAtsiliepimai` ADD FOREIGN KEY (`Apgyvendinimas`) REFERENCES `Apgyvendinimas` (`ID`);

ALTER TABLE `PersonaloAtsiliepimai` ADD FOREIGN KEY (`Personalas`) REFERENCES `Personalas` (`ID`);

ALTER TABLE `PersonaloAtsiliepimai` ADD FOREIGN KEY (`Ivertinimas`) REFERENCES `Ivertinimai` (`ID`);

ALTER TABLE `Mokejimai` ADD FOREIGN KEY (`ApgyvendinimasID`) REFERENCES `Apgyvendinimas` (`ID`);

ALTER TABLE `Mokejimai` ADD FOREIGN KEY (`BusenaID`) REFERENCES `MokejimuBusenos` (`ID`);

ALTER TABLE `Uzklausos` ADD FOREIGN KEY (`Apgyvendinimas`) REFERENCES `Apgyvendinimas` (`ID`);

ALTER TABLE `Uzklausos` ADD FOREIGN KEY (`PriskirtasPersonalas`) REFERENCES `Personalas` (`ID`);

ALTER TABLE `Uzklausos` ADD FOREIGN KEY (`Busena`) REFERENCES `UzklausuBusenos` (`ID`);
