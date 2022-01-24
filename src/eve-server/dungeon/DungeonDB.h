
/**
 * @name DungeonDB.h
 *   Dungeon DataBase methods
 *   Copyright 2018  Alasiya-EVEmu Team
 *
 * @Author:    Allan
 * @date:      13 December 2018
 *
 */

#ifndef _DUNGEON_DATABASE_H
#define _DUNGEON_DATABASE_H

class DungeonDB {
public:
    DungeonDB()                                         { /* do nothing here */ }
    ~DungeonDB()                                        { /* do nothing here */ }

    static void GetTemplates(DBQueryResult& res);
    static void GetFactions(DBQueryResult& res);
    static void GetRooms(uint32 dungeonID, DBQueryResult& res);
    static void GetArchetypes(DBQueryResult& res);
    static void GetDungeons(DBQueryResult& res);
    static void GetDungeons(uint32 dungeonID, DBQueryResult& res);
    static void GetDungeons(uint32 archetypeID, uint32 factionID, DBQueryResult& res);
    static void GetGroups(DBQueryResult& res);
    static void GetRoomObjects(uint32 roomID, std::vector< Dungeon::RoomObject >& into);

protected:

private:

};


#endif  // _DUNGEON_DATABASE_H