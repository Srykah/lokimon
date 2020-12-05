cmake_minimum_required(VERSION 3.18)
project(lokimon)

set(CMAKE_CXX_STANDARD 17)

set(fmt_ROOT "" CACHE PATH "fmt root directory. Leave blank for system default.")
find_package(fmt 7 REQUIRED CONFIG)
if(NOT fmt_FOUND)
    message(FATAL_ERROR "fmt not found; You should set fmt_ROOT to the fmt lib path")
endif()

add_subdirectory("${loki_src_root}" "${CMAKE_CURRENT_BINARY_DIR}/loki")

add_executable(lokimon
        src/main.cpp
        src/models/gameplay/Monster.cpp
        src/models/gameplay/Monster.hpp
        src/models/data/Elements.hpp
        src/models/gameplay/Trainer.hpp
        src/models/gameplay/Stats.hpp
        src/models/data/Species.hpp
        src/models/data/Species.cpp
        src/models/gameplay/BattleData.hpp
        src/models/gameplay/Player.hpp
        src/core/Application.cpp
        src/core/Application.hpp
        src/screens/battle/main/BattleScreen.cpp
        src/screens/battle/main/BattleScreen.hpp
        src/models/gameplay/Player.cpp
        src/models/data/Elements.cpp
        src/models/data/Constants.hpp
        src/models/gameplay/Trainer.cpp
        src/models/data/Attack.cpp
        src/models/data/Attack.hpp
        src/screens/battle/attackMenu/AttackMenuScreen.cpp
        src/screens/battle/attackMenu/AttackMenuScreen.hpp
        src/core/path.hpp
        src/models/other/TranslatedString.hpp
        src/models/other/TranslatedString.cpp
        src/models/gameplay/Stats.cpp
        src/screens/base/BaseScreen.hpp
        src/screens/base/BaseScreen.cpp
        src/screens/battle/main/BattleScreenView.cpp
        src/screens/battle/main/BattleScreenView.hpp
        src/screens/battle/attackMenu/AttackMenuScreenView.cpp
        src/screens/battle/attackMenu/AttackMenuScreenView.hpp
        src/core/ViewData.cpp
        src/core/ViewData.hpp
        src/models/data/GameData.cpp
        src/models/data/GameData.hpp
        src/models/data/AttackList.cpp
        src/models/data/AttackList.hpp
        src/models/data/SpeciesList.cpp
        src/models/data/SpeciesList.hpp
        src/screens/battle/attack/AttackScreen.cpp
        src/screens/battle/attack/AttackScreen.hpp
        src/screens/battle/intro/BattleIntroScreen.cpp
        src/screens/battle/intro/BattleIntroScreen.hpp
        src/screens/battle/gameOver/GameOverScreen.cpp
        src/screens/battle/gameOver/GameOverScreen.hpp
        src/screens/battle/victory/VictoryScreen.cpp
        src/screens/battle/victory/VictoryScreen.hpp)
target_include_directories(lokimon PRIVATE src)
target_link_libraries(lokimon fmt::fmt loki::input loki::gui loki::screens loki::sprites loki::tiles loki::window)