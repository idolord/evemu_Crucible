/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2021 The EVEmu Team
    For the latest information visit https://evemu.dev
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author:        Zhur (outline and 3 calls)
    Rewrite:    Allan
*/

#include "eve-server.h"

#include "PyServiceCD.h"
#include "cache/ObjCacheService.h"
#include "faction/FactionWarMgrService.h"

/*
 * FACWAR__ERROR
 * FACWAR__WARNING
 * FACWAR__INFO
 * FACWAR__MESSAGE
 * FACWAR__TRACE
 * FACWAR__CALL
 * FACWAR__CALL_DUMP
 * FACWAR__RSP_DUMP
 */

PyCallable_Make_InnerDispatcher(FactionWarMgrService)

FactionWarMgrService::FactionWarMgrService(PyServiceMgr *mgr)
: PyService(mgr, "facWarMgr"),
  m_dispatch(new Dispatcher(this))
{
    _SetCallDispatcher(m_dispatch);

    PyCallable_REG_CALL(FactionWarMgrService, GetWarFactions);
    PyCallable_REG_CALL(FactionWarMgrService, GetFWSystems);
    PyCallable_REG_CALL(FactionWarMgrService, GetMyCharacterRankOverview);
    PyCallable_REG_CALL(FactionWarMgrService, GetMyCharacterRankInfo);
    PyCallable_REG_CALL(FactionWarMgrService, GetFactionMilitiaCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, GetCharacterRankInfo);
    PyCallable_REG_CALL(FactionWarMgrService, GetFactionalWarStatus);
    PyCallable_REG_CALL(FactionWarMgrService, GetSystemStatus);
    PyCallable_REG_CALL(FactionWarMgrService, IsEnemyFaction);
    PyCallable_REG_CALL(FactionWarMgrService, JoinFactionAsCharacter);
    PyCallable_REG_CALL(FactionWarMgrService, GetCorporationWarFactionID);
    PyCallable_REG_CALL(FactionWarMgrService, IsEnemyCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, GetSystemsConqueredThisRun);
    PyCallable_REG_CALL(FactionWarMgrService, GetFactionCorporations);
    PyCallable_REG_CALL(FactionWarMgrService, JoinFactionAsCharacterRecommendationLetter);
    PyCallable_REG_CALL(FactionWarMgrService, JoinFactionAsAlliance);
    PyCallable_REG_CALL(FactionWarMgrService, JoinFactionAsCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_FactionInfo);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_TopAndAllKillsAndVPs);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_Character);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_Alliance);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_Militia);
    PyCallable_REG_CALL(FactionWarMgrService, GetStats_CorpPilots);
    PyCallable_REG_CALL(FactionWarMgrService, LeaveFactionAsAlliance);
    PyCallable_REG_CALL(FactionWarMgrService, LeaveFactionAsCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, WithdrawJoinFactionAsAlliance);
    PyCallable_REG_CALL(FactionWarMgrService, WithdrawJoinFactionAsCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, WithdrawLeaveFactionAsAlliance);
    PyCallable_REG_CALL(FactionWarMgrService, WithdrawLeaveFactionAsCorporation);
    PyCallable_REG_CALL(FactionWarMgrService, RefreshCorps);

}

FactionWarMgrService::~FactionWarMgrService()
{
    delete m_dispatch;
}

PyResult FactionWarMgrService::Handle_GetWarFactions(PyCallArgs &call) {
    ObjectCachedMethodID method_id(GetName(), "GetWarFactions");

    if (!m_manager->cache_service->IsCacheLoaded(method_id)) {
        PyRep *res = m_db.GetWarFactions();
        if (res == NULL)
            return nullptr;
        m_manager->cache_service->GiveCache(method_id, &res);
    }

    return m_manager->cache_service->MakeObjectCachedMethodCallResult(method_id);
}

PyResult FactionWarMgrService::Handle_GetFWSystems( PyCallArgs& call )
{
    /*
      [PySubStream 3625 bytes]
        [PyDict 171 kvp]
          [PyInt 30002813]
          [PyDict 2 kvp]
            [PyString "occupierID"]
            [PyInt 500001]
            [PyString "factionID"]
            [PyInt 500001]
          [PyInt 30005295]
          [PyDict 2 kvp]
            [PyString "occupierID"]
            [PyInt 500004]
            [PyString "factionID"]
            [PyInt 500004]
            */
    ObjectCachedMethodID method_id( GetName(), "GetFacWarSystems" );

    if ( !m_manager->cache_service->IsCacheLoaded( method_id ) )
    {
        PyRep* res = m_db.GetFacWarSystems();
        if ( res == NULL )
            return nullptr;

        m_manager->cache_service->GiveCache( method_id, &res );
    }

    return m_manager->cache_service->MakeObjectCachedMethodCallResult( method_id );
}

/**     ***********************************************************************
 * @note   these below are partially coded
 */

PyResult FactionWarMgrService::Handle_GetMyCharacterRankOverview( PyCallArgs& call ) {
    /**
            [PySubStream 122 bytes]
              [PyObjectEx Type2]
                [PyTuple 2 items]
                  [PyTuple 1 items]
                    [PyToken dbutil.CRowset]
                  [PyDict 1 kvp]
                    [PyString "header"]
                    [PyObjectEx Normal]
                      [PyTuple 2 items]
                        [PyToken blue.DBRowDescriptor]
                        [PyTuple 1 items]
                          [PyTuple 4 items]
                            [PyTuple 2 items]
                              [PyString "currentRank"]
                              [PyInt 3]
                            [PyTuple 2 items]
                              [PyString "highestRank"]
                              [PyInt 3]
                            [PyTuple 2 items]
                              [PyString "factionID"]
                              [PyInt 3]
                            [PyTuple 2 items]
                              [PyString "lastModified"]
                              [PyInt 64]
     */

// will need data from DB...
  util_Rowset rs;

    rs.header.push_back( "currentRank" );
    rs.header.push_back( "highestRank" );
    rs.header.push_back( "factionID" );
    rs.header.push_back( "lastModified" );

    return rs.Encode();
}

PyResult FactionWarMgrService::Handle_GetMyCharacterRankInfo( PyCallArgs& call ) {
  _log(FACWAR__CALL, "FacWarMgr::Handle_GetMyCharacterRankInfo() size=%li", call.tuple->size());
  call.Dump(FACWAR__CALL_DUMP);
  util_Rowset rs;

    rs.header.push_back( "currentRank" );
    rs.header.push_back( "highestRank" );
    rs.header.push_back( "factionID" );
    rs.header.push_back( "lastModified" );

    return rs.Encode();
}

PyResult FactionWarMgrService::Handle_GetFactionMilitiaCorporation(PyCallArgs &call) {
    /* 05:39:07 [SvcCall] Service facWarMgr: calling GetFactionMilitiaCorporation
     * 05:39:07 FactionWarMgrService::Handle_GetFactionMilitiaCorporation(): size= 1
     * 05:39:07 [SvcCall]   Call Arguments:
     * 05:39:07 [SvcCall]       Tuple: 1 elements
     * 05:39:07 [SvcCall]         [ 0] Integer field: 500002
     */
  _log(FACWAR__CALL, "FacWarMgr::Handle_GetFactionMilitiaCorporation() size=%li", call.tuple->size());
  call.Dump(FACWAR__CALL_DUMP);
    Call_SingleIntegerArg arg;
    if (!arg.Decode(&call.tuple)) {
        codelog(SERVICE__ERROR, "%s: Failed to decode arguments.", GetName());
        return nullptr;
    }
    return (new PyInt(m_db.GetFactionMilitiaCorporation(arg.arg)));
}

PyResult FactionWarMgrService::Handle_GetSystemStatus(PyCallArgs &call) {
    /*
     * status = self.facWarMgr.GetSystemStatus(session.solarsystemid2, session.warfactionid)
     * systemStatus = sm.StartService('facwar').GetSystemStatus()
     * xtra = ''
     * if systemStatus == const.contestionStateCaptured:
     *    xtra = localization.GetByLabel('UI/Neocom/SystemLost')
     *    elif systemStatus == const.contestionStateVulnerable:
     *    xtra = localization.GetByLabel('UI/Neocom/Vulnerable')
     *    elif systemStatus == const.contestionStateContested:
     *    xtra = localization.GetByLabel('UI/Neocom/Contested')
     *    elif systemStatus == const.contestionStateNone and returnNone:
     *    xtra = localization.GetByLabel('UI/Neocom/Uncontested')
     *    return xtra
     */

    _log(FACWAR__CALL, "FacWarMgr::Handle_GetSystemStatus()");
    call.Dump(FACWAR__CALL_DUMP);
    return new PyInt(FacWar::SysStatus::None);
}

// these next two should use static data or cached data to avoid db hits
PyResult FactionWarMgrService::Handle_IsEnemyFaction(PyCallArgs &call) {
    //  return self.facWarMgr.IsEnemyFaction(enemyID, factionID)
    /*
     * 05:39:09 L FactionWarMgrService::Handle_IsEnemyFaction(): size=2
     * 05:39:09 [SvcCall]   Call Arguments:
     * 05:39:09 [SvcCall]       Tuple: 2 elements
     * 05:39:09 [SvcCall]         [ 0] Integer field: 500002
     * 05:39:09 [SvcCall]         [ 1] Integer field: 500001   <- this one changes
     */
    _log(FACWAR__CALL, "FacWarMgr::Handle_IsEnemyFaction()");
    call.Dump(FACWAR__CALL_DUMP);

    // return boolean
    return PyStatic.NewFalse();
}

PyResult FactionWarMgrService::Handle_IsEnemyCorporation(PyCallArgs &call) {
    //return self.facWarMgr.IsEnemyCorporation(enemyID, factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_IsEnemyCorporation()");
    call.Dump(FACWAR__CALL_DUMP);

    // return boolean
    return PyStatic.NewFalse();
}

/**     ***********************************************************************
 * @note   these do absolutely nothing at this time....
 */

PyResult FactionWarMgrService::Handle_GetCharacterRankInfo(PyCallArgs &call) {
  _log(FACWAR__CALL, "FacWarMgr::Handle_GetCharacterRankInfo()");
  call.Dump(FACWAR__CALL_DUMP);

  return nullptr;
}

//22:48:28 L FactionWarMgrService::Handle_GetFactionalWarStatus(): size= 0
PyResult FactionWarMgrService::Handle_GetFactionalWarStatus(PyCallArgs &call) {
  _log(FACWAR__CALL, "FacWarMgr::Handle_GetFactionalWarStatus()");
  call.Dump(FACWAR__CALL_DUMP);

  return nullptr;
}

PyResult FactionWarMgrService::Handle_JoinFactionAsCharacter(PyCallArgs &call) {
  _log(FACWAR__CALL, "FacWarMgr::Handle_JoinFactionAsCharacter()");
  call.Dump(FACWAR__CALL_DUMP);

  return nullptr;
}

PyResult FactionWarMgrService::Handle_GetCorporationWarFactionID(PyCallArgs &call) {
    //ret = self.facWarMgr.GetCorporationWarFactionID(corpID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetCorporationWarFactionID()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetSystemsConqueredThisRun(PyCallArgs &call) {
    /*
        systemsThatWillSwitchNextDownTime = self.GetSystemsConqueredThisRun()
        cfg.evelocations.Prime([ d['solarsystemID'] for d in systemsThatWillSwitchNextDownTime ])
        cfg.eveowners.Prime([ d['occupierID'] for d in systemsThatWillSwitchNextDownTime ])
        */
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetSystemsConqueredThisRun()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetFactionCorporations(PyCallArgs &call) {
    //return self.facWarMgr.GetFactionCorporations(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetFactionCorporations()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_JoinFactionAsCharacterRecommendationLetter(PyCallArgs &call) {
    //self.facWarMgr.JoinFactionAsCharacterRecommendationLetter, factionID, itemID)
    // if char standing with faction is < 0.5,
    // they can join provided they have a 'recommendation letter', typeID 30906
    // dunno if the letter is removed after joining.
    _log(FACWAR__CALL, "FacWarMgr::Handle_JoinFactionAsCharacterRecommendationLetter()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_JoinFactionAsAlliance(PyCallArgs &call) {
    //self.facWarMgr.JoinFactionAsAlliance(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_JoinFactionAsAlliance()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_JoinFactionAsCorporation(PyCallArgs &call) {
    //self.facWarMgr.JoinFactionAsCorporation(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_JoinFactionAsCorporation()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_FactionInfo(PyCallArgs &call) {
    //return self.facWarMgr.GetStats_FactionInfo()
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_FactionInfo()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_TopAndAllKillsAndVPs(PyCallArgs &call) {
    //self.topStats = self.facWarMgr.GetStats_TopAndAllKillsAndVPs()
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_TopAndAllKillsAndVPs()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_Character(PyCallArgs &call) {
    //for k, v in self.facWarMgr.GetStats_Character().items():
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_Character()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_Corp(PyCallArgs &call) {
    // for k, v in self.facWarMgr.GetStats_Corp().items():
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_Corp()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_Alliance(PyCallArgs &call) {
    //for k, v in self.facWarMgr.GetStats_Alliance().items():
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_Alliance()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_Militia(PyCallArgs &call) {
    //return self.facWarMgr.GetStats_Militia()
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_Militia()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_GetStats_CorpPilots(PyCallArgs &call) {
    //return self.facWarMgr.GetStats_CorpPilots()
    _log(FACWAR__CALL, "FacWarMgr::Handle_GetStats_CorpPilots()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_LeaveFactionAsAlliance(PyCallArgs &call) {
    //self.facWarMgr.LeaveFactionAsAlliance(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_LeaveFactionAsAlliance()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_LeaveFactionAsCorporation(PyCallArgs &call) {
    //self.facWarMgr.LeaveFactionAsCorporation(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_LeaveFactionAsCorporation()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_WithdrawJoinFactionAsAlliance(PyCallArgs &call) {
    //self.facWarMgr.WithdrawJoinFactionAsAlliance(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_WithdrawJoinFactionAsAlliance()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_WithdrawJoinFactionAsCorporation(PyCallArgs &call) {
    //self.facWarMgr.WithdrawJoinFactionAsCorporation(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_WithdrawJoinFactionAsCorporation()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_WithdrawLeaveFactionAsAlliance(PyCallArgs &call) {
    //self.facWarMgr.WithdrawLeaveFactionAsAlliance(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_WithdrawLeaveFactionAsAlliance()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_WithdrawLeaveFactionAsCorporation(PyCallArgs &call) {
    //self.facWarMgr.WithdrawLeaveFactionAsCorporation(factionID)
    _log(FACWAR__CALL, "FacWarMgr::Handle_WithdrawLeaveFactionAsCorporation()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

PyResult FactionWarMgrService::Handle_RefreshCorps(PyCallArgs &call) {
    //return self.facWarMgr.RefreshCorps()
    _log(FACWAR__CALL, "FacWarMgr::Handle_RefreshCorps()");
    call.Dump(FACWAR__CALL_DUMP);

    return nullptr;
}

