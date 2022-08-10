target_sources(lokimon PRIVATE
  # base
  base/BaseScreen.cpp
  base/BaseScreen.hpp
  # battle
  battle/attackCutscene/AttackCutsceneScreen.cpp
  battle/attackCutscene/AttackCutsceneScreen.hpp
  battle/attackMenu/AttackMenuScreen.cpp
  battle/attackMenu/AttackMenuScreen.hpp
  battle/attackMenu/AttackMenuScreenView.cpp
  battle/attackMenu/AttackMenuScreenView.hpp
  battle/gameOver/GameOverScreen.cpp
  battle/gameOver/GameOverScreen.hpp
  battle/intro/BattleIntroScreen.cpp
  battle/intro/BattleIntroScreen.hpp
  battle/main/BattleScreen.cpp
  battle/main/BattleScreen.hpp
  battle/main/BattleScreenView.cpp
  battle/main/BattleScreenView.hpp
  battle/victory/VictoryScreen.cpp
  battle/victory/VictoryScreen.hpp
  # map
  map/main/MapScreen.cpp
  map/main/MapScreen.hpp
  map/main/MapScreenView.cpp
  map/main/MapScreenView.hpp
  map/player/PlayerController.cpp
  map/player/PlayerController.hpp
  )