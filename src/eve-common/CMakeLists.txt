#
# CMake build system file for EVEmu.
#
# Author: Bloody.Rabbit
#

##############
# Initialize #
##############
SET( TARGET_NAME        "eve-common" )
SET( TARGET_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/src/${TARGET_NAME}" )
SET( TARGET_SOURCE_DIR  "${PROJECT_SOURCE_DIR}/src/${TARGET_NAME}" )
SET( TARGET_PACKETS_DIR "${PROJECT_BINARY_DIR}/src/${TARGET_NAME}" )

#########
# Files #
#########
SET( INCLUDE
     "${TARGET_INCLUDE_DIR}/eve-common.h"
     "${TARGET_INCLUDE_DIR}/EVE_Consts.h"
     "${TARGET_INCLUDE_DIR}/EVE_Corp.h"
     "${TARGET_INCLUDE_DIR}/EVE_Defines.h"
     "${TARGET_INCLUDE_DIR}/EVE_Dungeon.h"
     "${TARGET_INCLUDE_DIR}/EVE_Effects.h"
     "${TARGET_INCLUDE_DIR}/EVE_Flags.h"
     "${TARGET_INCLUDE_DIR}/EVE_Inventory.h"
     "${TARGET_INCLUDE_DIR}/EVE_LSC.h"
     "${TARGET_INCLUDE_DIR}/EVE_Mail.h"
     "${TARGET_INCLUDE_DIR}/EVE_Market.h"
     "${TARGET_INCLUDE_DIR}/EVE_Planet.h"
     "${TARGET_INCLUDE_DIR}/EVE_POS.h"
     "${TARGET_INCLUDE_DIR}/EVE_Roles.h"
     "${TARGET_INCLUDE_DIR}/EVE_Scanning.h"
     "${TARGET_INCLUDE_DIR}/EVE_Skills.h"
     "${TARGET_INCLUDE_DIR}/EVE_Spawn.h"
     "${TARGET_INCLUDE_DIR}/EVE_Typedefs.h"
     "${TARGET_INCLUDE_DIR}/EVE_Wallet.h"
     "${TARGET_INCLUDE_DIR}/EVE_Station.h")
SET( SOURCE
     "" )

SET( auth_INCLUDE
     "${TARGET_INCLUDE_DIR}/auth/BinAsciiModule.h"
     "${TARGET_INCLUDE_DIR}/auth/PasswordModule.h"
     "${TARGET_INCLUDE_DIR}/auth/ShaModule.h" )
SET( auth_SOURCE
     "${TARGET_SOURCE_DIR}/auth/PasswordModule.cpp" )

SET( cache_INCLUDE
     "${TARGET_INCLUDE_DIR}/cache/CachedObjectMgr.h" )
SET( cache_SOURCE
     "${TARGET_SOURCE_DIR}/cache/CachedObjectMgr.cpp" )

SET( database_INCLUDE
     "${TARGET_INCLUDE_DIR}/database/EVEDBUtils.h"
     "${TARGET_INCLUDE_DIR}/database/RowsetReader.h"
     "${TARGET_INCLUDE_DIR}/database/RowsetToSQL.h" )
SET( database_SOURCE
     "${TARGET_SOURCE_DIR}/database/EVEDBUtils.cpp"
     "${TARGET_SOURCE_DIR}/database/RowsetReader.cpp"
     "${TARGET_SOURCE_DIR}/database/RowsetToSQL.cpp" )

SET( destiny_INCLUDE
     "${TARGET_INCLUDE_DIR}/destiny/DestinyBinDump.h"
     "${TARGET_INCLUDE_DIR}/destiny/DestinyStructs.h" )
SET( destiny_SOURCE
     "${TARGET_SOURCE_DIR}/destiny/DestinyBinDump.cpp" )

SET( marshal_INCLUDE
     "${TARGET_INCLUDE_DIR}/marshal/EVEMarshal.h"
     "${TARGET_INCLUDE_DIR}/marshal/EVEMarshalOpcodes.h"
     "${TARGET_INCLUDE_DIR}/marshal/EVEMarshalStringTable.h"
     "${TARGET_INCLUDE_DIR}/marshal/EVEUnmarshal.h" )
SET( marshal_SOURCE
     "${TARGET_SOURCE_DIR}/marshal/EVEMarshal.cpp"
     "${TARGET_SOURCE_DIR}/marshal/EVEMarshalStringTable.cpp"
     "${TARGET_SOURCE_DIR}/marshal/EVEUnmarshal.cpp" )

SET( network_INCLUDE
     "${TARGET_INCLUDE_DIR}/network/EVEPktDispatch.h"
     "${TARGET_INCLUDE_DIR}/network/EVESession.h"
     "${TARGET_INCLUDE_DIR}/network/EVETCPConnection.h"
     "${TARGET_INCLUDE_DIR}/network/EVETCPServer.h"
     "${TARGET_INCLUDE_DIR}/network/packet_types.h" )
SET( network_SOURCE
     "${TARGET_SOURCE_DIR}/network/EVEPktDispatch.cpp"
     "${TARGET_SOURCE_DIR}/network/EVESession.cpp"
     "${TARGET_SOURCE_DIR}/network/EVETCPConnection.cpp" )

SET( packets_INCLUDE
     "${TARGET_PACKETS_DIR}/packets/AccountPkts.h"
     "${TARGET_PACKETS_DIR}/packets/Bookmarks.h"
     "${TARGET_PACKETS_DIR}/packets/BulkDataPkts.h"
     "${TARGET_PACKETS_DIR}/packets/Calendar.h"
     "${TARGET_PACKETS_DIR}/packets/Character.h"
     "${TARGET_PACKETS_DIR}/packets/CorporationPkts.h"
     "${TARGET_PACKETS_DIR}/packets/Contracts.h"
     "${TARGET_PACKETS_DIR}/packets/Crypto.h"
     "${TARGET_PACKETS_DIR}/packets/Destiny.h"
     "${TARGET_PACKETS_DIR}/packets/DogmaIM.h"
     "${TARGET_PACKETS_DIR}/packets/Fleet.h"
     "${TARGET_PACKETS_DIR}/packets/General.h"
     "${TARGET_PACKETS_DIR}/packets/Inventory.h"
     "${TARGET_PACKETS_DIR}/packets/LSCPkts.h"
     "${TARGET_PACKETS_DIR}/packets/Language.h"
     "${TARGET_PACKETS_DIR}/packets/Mail.h"
     "${TARGET_PACKETS_DIR}/packets/Map.h"
     "${TARGET_PACKETS_DIR}/packets/Manufacturing.h"
     "${TARGET_PACKETS_DIR}/packets/Market.h"
     "${TARGET_PACKETS_DIR}/packets/Missions.h"
     "${TARGET_PACKETS_DIR}/packets/Missile.h"
     "${TARGET_PACKETS_DIR}/packets/ObjectCaching.h"
     "${TARGET_PACKETS_DIR}/packets/Planet.h"
     "${TARGET_PACKETS_DIR}/packets/POS.h"
     "${TARGET_PACKETS_DIR}/packets/Repair.h"
     "${TARGET_PACKETS_DIR}/packets/Scan.h"
     #"${TARGET_PACKETS_DIR}/packets/Salvage.h"
     "${TARGET_PACKETS_DIR}/packets/Sovereignty.h"
     "${TARGET_PACKETS_DIR}/packets/Standing.h"
     "${TARGET_PACKETS_DIR}/packets/Trade.h"
     "${TARGET_PACKETS_DIR}/packets/Tutorial.h"
     "${TARGET_PACKETS_DIR}/packets/Wallet.h" )
SET( packets_SOURCE
     "${TARGET_PACKETS_DIR}/packets/AccountPkts.cpp"
     "${TARGET_PACKETS_DIR}/packets/Bookmarks.cpp"
     "${TARGET_PACKETS_DIR}/packets/BulkDataPkts.cpp"
     "${TARGET_PACKETS_DIR}/packets/Calendar.cpp"
     "${TARGET_PACKETS_DIR}/packets/Character.cpp"
     "${TARGET_PACKETS_DIR}/packets/CorporationPkts.cpp"
     "${TARGET_PACKETS_DIR}/packets/Contracts.cpp"
     "${TARGET_PACKETS_DIR}/packets/Crypto.cpp"
     "${TARGET_PACKETS_DIR}/packets/Destiny.cpp"
     "${TARGET_PACKETS_DIR}/packets/DogmaIM.cpp"
     "${TARGET_PACKETS_DIR}/packets/Fleet.cpp"
     "${TARGET_PACKETS_DIR}/packets/General.cpp"
     "${TARGET_PACKETS_DIR}/packets/Inventory.cpp"
     "${TARGET_PACKETS_DIR}/packets/LSCPkts.cpp"
     "${TARGET_PACKETS_DIR}/packets/Language.cpp"
     "${TARGET_PACKETS_DIR}/packets/Mail.cpp"
     "${TARGET_PACKETS_DIR}/packets/Map.cpp"
     "${TARGET_PACKETS_DIR}/packets/Manufacturing.cpp"
     "${TARGET_PACKETS_DIR}/packets/Market.cpp"
     "${TARGET_PACKETS_DIR}/packets/Missions.cpp"
     "${TARGET_PACKETS_DIR}/packets/Missile.cpp"
     "${TARGET_PACKETS_DIR}/packets/ObjectCaching.cpp"
     "${TARGET_PACKETS_DIR}/packets/Planet.cpp"
     "${TARGET_PACKETS_DIR}/packets/POS.cpp"
     "${TARGET_PACKETS_DIR}/packets/Repair.cpp"
     #"${TARGET_PACKETS_DIR}/packets/Salvage.cpp"
     "${TARGET_PACKETS_DIR}/packets/Scan.cpp"
     "${TARGET_PACKETS_DIR}/packets/Sovereignty.cpp"
     "${TARGET_PACKETS_DIR}/packets/Standing.cpp"
     "${TARGET_PACKETS_DIR}/packets/Trade.cpp"
     "${TARGET_PACKETS_DIR}/packets/Tutorial.cpp"
     "${TARGET_PACKETS_DIR}/packets/Wallet.cpp" )
SET( packets_XMLP
     "${TARGET_SOURCE_DIR}/packets/AccountPkts.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Bookmarks.xmlp"
     "${TARGET_SOURCE_DIR}/packets/BulkDataPkts.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Calendar.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Character.xmlp"
     "${TARGET_SOURCE_DIR}/packets/CorporationPkts.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Contracts.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Crypto.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Destiny.xmlp"
     "${TARGET_SOURCE_DIR}/packets/DogmaIM.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Fleet.xmlp"
     "${TARGET_SOURCE_DIR}/packets/General.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Inventory.xmlp"
     "${TARGET_SOURCE_DIR}/packets/LSCPkts.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Language.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Mail.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Map.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Manufacturing.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Market.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Missions.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Missile.xmlp"
     "${TARGET_SOURCE_DIR}/packets/ObjectCaching.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Planet.xmlp"
     "${TARGET_SOURCE_DIR}/packets/POS.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Repair.xmlp"
     #"${TARGET_SOURCE_DIR}/packets/Salvage.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Scan.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Sovereignty.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Standing.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Trade.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Tutorial.xmlp"
     "${TARGET_SOURCE_DIR}/packets/Wallet.xmlp" )

SET( python_INCLUDE
     "${TARGET_INCLUDE_DIR}/python/PyDumpVisitor.h"
     "${TARGET_INCLUDE_DIR}/python/PyLookupDump.h"
     "${TARGET_INCLUDE_DIR}/python/PyPacket.h"
     "${TARGET_INCLUDE_DIR}/python/PyRep.h"
     "${TARGET_INCLUDE_DIR}/python/PyTraceLog.h"
     "${TARGET_INCLUDE_DIR}/python/PyVisitor.h"
     "${TARGET_INCLUDE_DIR}/python/PyXMLGenerator.h" )
SET( python_SOURCE
     "${TARGET_SOURCE_DIR}/python/PyDumpVisitor.cpp"
     "${TARGET_SOURCE_DIR}/python/PyLookupDump.cpp"
     "${TARGET_SOURCE_DIR}/python/PyPacket.cpp"
     "${TARGET_SOURCE_DIR}/python/PyRep.cpp"
     "${TARGET_SOURCE_DIR}/python/PyVisitor.cpp"
     "${TARGET_SOURCE_DIR}/python/PyXMLGenerator.cpp" )

SET( python_classes_INCLUDE
     "${TARGET_INCLUDE_DIR}/python/classes/PyDatabase.h"
     "${TARGET_INCLUDE_DIR}/python/classes/PyExceptions.h"
     "${TARGET_INCLUDE_DIR}/python/classes/PyUtils.h" )
SET( python_classes_SOURCE
     "${TARGET_SOURCE_DIR}/python/classes/PyDatabase.cpp"
     "${TARGET_SOURCE_DIR}/python/classes/PyExceptions.cpp"
     "${TARGET_SOURCE_DIR}/python/classes/PyUtils.cpp" )

SET( tables_INCLUDE
     "${TARGET_INCLUDE_DIR}/tables/invCategories.h"
     "${TARGET_INCLUDE_DIR}/tables/invGroups.h"
     "${TARGET_INCLUDE_DIR}/tables/invTypes.h" )
SET( tables_SOURCE
     "" )

SET( utils_INCLUDE
     "${TARGET_INCLUDE_DIR}/utils/EvEMath.h"
     "${TARGET_INCLUDE_DIR}/utils/EVEUtils.h"
     "${TARGET_INCLUDE_DIR}/utils/EvilNumber.h")
SET( utils_SOURCE
     "${TARGET_SOURCE_DIR}/utils/EvEMath.cpp"
     "${TARGET_SOURCE_DIR}/utils/EVEUtils.cpp"
     "${TARGET_SOURCE_DIR}/utils/EvilNumber.cpp")

#####################
# Setup the library #
#####################
SOURCE_GROUP( "src"                  FILES ${INCLUDE} )
SOURCE_GROUP( "src\\auth"            FILES ${auth_INCLUDE} )
SOURCE_GROUP( "src\\cache"           FILES ${cache_INCLUDE} )
SOURCE_GROUP( "src\\database"        FILES ${database_INCLUDE} )
SOURCE_GROUP( "src\\destiny"         FILES ${destiny_INCLUDE} )
SOURCE_GROUP( "src\\marshal"         FILES ${marshal_INCLUDE} )
SOURCE_GROUP( "src\\network"         FILES ${network_INCLUDE} )
SOURCE_GROUP( "src\\packets"         FILES ${packets_INCLUDE} )
SOURCE_GROUP( "src\\python"          FILES ${python_INCLUDE} )
SOURCE_GROUP( "src\\python\\classes" FILES ${python_classes_INCLUDE} )
SOURCE_GROUP( "src\\tables"          FILES ${tables_INCLUDE} )
SOURCE_GROUP( "src\\utils"           FILES ${utils_INCLUDE} )

SOURCE_GROUP( "src"                  FILES ${SOURCE} )
SOURCE_GROUP( "src\\auth"            FILES ${auth_SOURCE} )
SOURCE_GROUP( "src\\cache"           FILES ${cache_SOURCE} )
SOURCE_GROUP( "src\\database"        FILES ${database_SOURCE} )
SOURCE_GROUP( "src\\destiny"         FILES ${destiny_SOURCE} )
SOURCE_GROUP( "src\\marshal"         FILES ${marshal_SOURCE} )
SOURCE_GROUP( "src\\network"         FILES ${network_SOURCE} )
SOURCE_GROUP( "src\\packets"         FILES ${packets_SOURCE} )
SOURCE_GROUP( "src\\packets\\xmlp"   FILES ${packets_XMLP} )
SOURCE_GROUP( "src\\python"          FILES ${python_SOURCE} )
SOURCE_GROUP( "src\\python\\classes" FILES ${python_classes_SOURCE} )
SOURCE_GROUP( "src\\tables"          FILES ${tables_SOURCE} )
SOURCE_GROUP( "src\\utils"           FILES ${utils_SOURCE} )

FILE( MAKE_DIRECTORY "${TARGET_PACKETS_DIR}/packets" )
ADD_CUSTOM_COMMAND( OUTPUT ${packets_INCLUDE} ${packets_SOURCE}
                    COMMAND "eve-xmlpktgen"
                    ARGS -I "${TARGET_PACKETS_DIR}/packets"
                         -S "${TARGET_PACKETS_DIR}/packets"
                         ${packets_XMLP}
                    DEPENDS "eve-xmlpktgen"
                    COMMENT "Generating packet files..." )

ADD_LIBRARY( "${TARGET_NAME}"
             ${INCLUDE}                ${SOURCE}
             ${auth_INCLUDE}           ${auth_SOURCE}
             ${cache_INCLUDE}          ${cache_SOURCE}
             ${database_INCLUDE}       ${database_SOURCE}
             ${destiny_INCLUDE}        ${destiny_SOURCE}
             ${marshal_INCLUDE}        ${marshal_SOURCE}
             ${network_INCLUDE}        ${network_SOURCE}
             ${packets_INCLUDE}        ${packets_SOURCE}        ${packets_XMLP}
             ${python_INCLUDE}         ${python_SOURCE}
             ${python_classes_INCLUDE} ${python_classes_SOURCE}
             ${tables_INCLUDE}         ${tables_SOURCE}
             ${utils_INCLUDE}          ${utils_SOURCE} )

TARGET_BUILD_PCH( "${TARGET_NAME}"
                  "${TARGET_INCLUDE_DIR}/eve-common.h"
                  "${TARGET_SOURCE_DIR}/utils/EVEUtils.cpp" )
TARGET_INCLUDE_DIRECTORIES( "${TARGET_NAME}"
                            ${UTF8CPP_INCLUDE_DIRS}
                            ${UTILS_INCLUDE_DIRS}
                            ${eve-core_INCLUDE_DIRS}
                            "${TARGET_INCLUDE_DIR}"
                            "${TARGET_PACKETS_DIR}" )
TARGET_LINK_LIBRARIES( "${TARGET_NAME}"
                       ${UTILS_LIBRARIES}
                       "eve-core" )
