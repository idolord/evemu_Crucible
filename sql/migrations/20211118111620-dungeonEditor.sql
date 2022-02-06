-- Dungeon Editor data
-- +migrate Up
ALTER TABLE dunTemplates
    ADD COLUMN dunTemplateDescription VARCHAR(400) NOT NULL DEFAULT "" AFTER dunTemplateName;
ALTER TABLE dunTemplates
    ADD COLUMN dunTemplateFactionID INT(10) NOT NULL DEFAULT 0 AFTER dunTemplateDescription;
CREATE TABLE dunArchetypes (
    archetypeID INT(10),
    archetypeName VARCHAR(100));
INSERT INTO dunArchetypes
VALUES
    (1,"Mission"),
    (2,"Gravimetric"),
    (3,"Magnetometric"),
    (4,"Radar"),
    (5,"Ladar"),
    (6,"Wormhole"),
    (7,"Anomaly"),
    (8,"Unrated"),
    (9,"Escalation"),
    (10,"Rated");
CREATE TABLE dunDungeons (
    dungeonID INT(10) NOT NULL,
    dungeonName VARCHAR(100) NOT NULL DEFAULT "",
    dungeonStatus INT(10) NOT NULL DEFAULT 0,
    factionID INT(10) NOT NULL DEFAULT 0,
    archetypeID INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (dungeonID));
CREATE TABLE dunGroups (
    groupID INT(10) NOT NULL,
    groupName VARCHAR(100) NOT NULL DEFAULT "",
    yaw DOUBLE NOT NULL DEFAULT 0,
    pitch DOUBLE NOT NULL DEFAULT 0,
    roll DOUBLE NOT NULL DEFAULT 0);
CREATE TABLE dunRooms (
    roomID INT(10) NOT NULL,
    roomName VARCHAR(100) NOT NULL DEFAULT "",
    dungeonID INT(10) NOT NULL);
INSERT INTO dunGroups (groupID)
SELECT DISTINCT
    dunGroupID as groupID
FROM
    dunGroupData;
UPDATE dunGroups g
    SET groupName=CONCAT(
    CASE
        WHEN SUBSTRING(g.groupID,1,1) = 1 THEN "Decorative"
        WHEN SUBSTRING(g.groupID,1,1) = 2 THEN "SEB"
        WHEN SUBSTRING(g.groupID,1,1) = 3 THEN "Mining"
        WHEN SUBSTRING(g.groupID,1,1) = 4 THEN "LCO"
        WHEN SUBSTRING(g.groupID,1,1) = 5 THEN "Ships"
        WHEN SUBSTRING(g.groupID,1,1) = 6 THEN "Base"
        WHEN SUBSTRING(g.groupID,1,1) = 7 THEN "StGun"
        WHEN SUBSTRING(g.groupID,1,1) = 8 THEN "StWreck"
        WHEN SUBSTRING(g.groupID,1,1) = 9 THEN "Misc"
        ELSE ""
    END, "_",
    CASE
        WHEN SUBSTRING(g.groupID,2,1) = 1 THEN "SpObj"
        WHEN SUBSTRING(g.groupID,2,1) = 2 THEN "EfBeac"
        WHEN SUBSTRING(g.groupID,2,1) = 3 THEN "RoidType"
        WHEN SUBSTRING(g.groupID,2,1) = 4 THEN "IceType"
        WHEN SUBSTRING(g.groupID,2,1) = 6 THEN "RoidColony"
        WHEN SUBSTRING(g.groupID,2,1) = 9 THEN "Misc"
        ELSE "null"
    END, "_(legacy)");

CREATE TABLE dunRoomObjects (
    objectID INT(10) NOT NULL AUTO_INCREMENT,
    roomID INT(10) NOT NULL,
    typeID INT(10) NOT NULL,
    groupID INT(10) NOT NULL,
    x DOUBLE NOT NULL DEFAULT 0,
    y DOUBLE NOT NULL DEFAULT 0,
    z DOUBLE NOT NULL DEFAULT 0,
    yaw DOUBLE NOT NULL DEFAULT 0,
    pitch DOUBLE NOT NULL DEFAULT 0,
    roll DOUBLE NOT NULL DEFAULT 0,
    radius INT(11) NOT NULL DEFAULT 0,
    PRIMARY KEY(objectID)
);

-- +migrate Down
ALTER TABLE dunTemplates
    DROP COLUMN dunTemplateDescription;
ALTER TABLE dunTemplates
    DROP COLUMN dunTemplateFactionID;
DROP TABLE dunArchetypes;
DROP TABLE dunDungeons;
DROP TABLE dunGroups;
DROP TABLE dunRooms;
DROP TABLE dunRoomObjects;