
/**
 * @name DungeonDB.cpp
 *   Dungeon DataBase methods
 *   Copyright 2018  Alasiya-EVEmu Team
 *
 * @Author:    Allan
 * @date:      13 December 2018
 *
 */


/* Dungeon Logging
 * DUNG__ERROR
 * DUNG__WARNING
 * DUNG__INFO
 * DUNG__MESSAGE
 * DUNG__TRACE
 * DUNG__CALL
 * DUNG__CALL_DUMP
 * DUNG__RSP_DUMP
 * DUNG__DB_ERROR
 * DUNG__DB_WARNING
 * DUNG__DB_INFO
 * DUNG__DB_MESSAGE
 */

#include "eve-server.h"

#include "DungeonDB.h"


void DungeonDB::GetTemplates(DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT dunTemplateID as templateID, dunTemplateName as templateName, "
    "dunTemplateDescription as description "
    "FROM dunTemplates"))
        _log(DATABASE__ERROR, "Error in GetDunTemplates query: %s", res.error.c_str());
}

void DungeonDB::GetFactions(DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT factionID FROM facFactions"))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetRooms(uint32 dungeonID, DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT roomID, roomName "
    "FROM dunRooms "
    "WHERE dungeonID=%u", dungeonID))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetArchetypes(DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT archetypeID, archetypeName FROM dunArchetypes"))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetDungeons(DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT dungeonID, dungeonName, dungeonStatus, NULL as dungeonNameID, factionID, archetypeID "
    "FROM dunDungeons"))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetDungeons(uint32 dungeonID, DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT dungeonID, dungeonName, dungeonStatus, NULL as dungeonNameID, factionID, archetypeID "
    "FROM dunDungeons "
    "WHERE dungeonID=%u", dungeonID))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetDungeons(uint32 archetypeID, uint32 factionID, DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT dungeonID, dungeonName, dungeonStatus, NULL as dungeonNameID, factionID, archetypeID "
    "FROM dunDungeons "
    "WHERE archetypeID=%u AND factionID=%u", archetypeID, factionID))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetGroups(DBQueryResult& res)
{
    if (!sDatabase.RunQuery(res, "SELECT groupID, groupName FROM dunGroups"))
    _log(DATABASE__ERROR, "Error in GetFactions query: %s", res.error.c_str());
}

void DungeonDB::GetRoomObjects(uint32 roomID, std::vector< Dungeon::RoomObject >& into)
{
    DBQueryResult res;

    if (!sDatabase.RunQuery(res, "SELECT roomID, typeID, x, y, z, yaw, pitch, roll, radius "
    "FROM dunRoomObjects "
    "WHERE roomID=%u", roomID))
    _log(DATABASE__ERROR, "Error in GetRoomObjects query: %s", res.error.c_str());

    _log(DATABASE__RESULTS, "GetRoomObjects returned %lu items", res.GetRowCount());
    DBResultRow row;

    while(res.GetRow(row)) {
        Dungeon::RoomObject entry = Dungeon::RoomObject();
            entry.roomID = row.GetInt(0);
            entry.typeID = row.GetInt(1);
            entry.x = row.GetInt(2);
            entry.y = row.GetInt(3);
            entry.z = row.GetInt(4);
            entry.pitch = row.GetDouble(5);
            entry.roll = row.GetDouble(6);
            entry.yaw = row.GetDouble(7);
            entry.radius = row.GetInt(8);
        into.push_back(entry);
    }
}


