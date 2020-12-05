/*!
 * \file Elements.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Elements.hpp"
#include <stdexcept>

namespace {

// helper defines (will get undefed below)
#define WORST mon::Effectiveness::WORST
#define BAD mon::Effectiveness::BAD
#define NORMAL mon::Effectiveness::NORMAL
#define GOOD mon::Effectiveness::GOOD
#define BEST mon::Effectiveness::BEST

/*
 * outer index: attacking monster
 * inner index: defending monster
 */
constexpr mon::Effectiveness ELEMENT_EFFECTIVENESS[static_cast<unsigned int>(
    mon::Element::COUNT)][static_cast<unsigned int>(mon::Element::COUNT)]{
    // clang-format off
    //             WATER   FIRE    ICE     WIND    AURA    POISON  ELEC    METAL   EARTH
    /*  WATER */ { BAD,    BEST,   NORMAL, NORMAL, GOOD,   WORST,  BAD,    NORMAL, NORMAL, },
    /*   FIRE */ { WORST,  BAD,    BEST,   NORMAL, NORMAL, NORMAL, NORMAL, GOOD,   BAD,    },
    /*    ICE */ { NORMAL, WORST,  BAD,    BEST,   BAD,    NORMAL, NORMAL, NORMAL, GOOD,   },
    /*   WIND */ { NORMAL, NORMAL, WORST,  BAD,    BEST,   GOOD,   NORMAL, BAD,    NORMAL, },
    /*   AURA */ { BAD,    NORMAL, GOOD,   WORST,  BAD,    BEST,   NORMAL, NORMAL, NORMAL, },
    /* POISON */ { BEST,   NORMAL, NORMAL, BAD,    WORST,  BAD,    GOOD,   NORMAL, NORMAL, },
    /*   ELEC */ { GOOD,   NORMAL, NORMAL, NORMAL, NORMAL, BAD,    BAD,    BEST,   WORST,  },
    /*  METAL */ { NORMAL, BAD,    NORMAL, GOOD,   NORMAL, NORMAL, WORST,  BAD,    BEST,   },
    /*  EARTH */ { NORMAL, GOOD,   BAD,    NORMAL, NORMAL, NORMAL, BEST,   WORST,  BAD,    },
    // clang-format on
};

/*
 * outer index : attacking monster
 * inner index : defending monster
 */
constexpr mon::Effectiveness FAMILY_EFFECTIVENESS[static_cast<unsigned int>(
    mon::Family::COUNT)][static_cast<unsigned int>(mon::Family::COUNT)]{
    // clang-format off
    //             BIRD    INSECT  PLANT   REPT    BEAST   DINO    DRAGON    
    /*   BIRD */ { BAD,    BEST,   BAD,    GOOD,   NORMAL, NORMAL, WORST,  },
    /* INSECT */ { WORST,  BAD,    BEST,   NORMAL, BAD,    GOOD,   NORMAL, },
    /*  PLANT */ { GOOD,   WORST,  BAD,    BEST,   NORMAL, BAD,    NORMAL, },
    /*   REPT */ { BAD,    NORMAL, WORST,  BAD,    BEST,   NORMAL, GOOD,   },
    /*  BEAST */ { NORMAL, GOOD,   NORMAL, WORST,  BAD,    BEST,   BAD,    },
    /*   DINO */ { NORMAL, BAD,    GOOD,   NORMAL, WORST,  BAD,    BEST,   },
    /* DRAGON */ { BEST,   NORMAL, NORMAL, BAD,    GOOD,   WORST,  BAD,    },
    // clang-format on
};

// undef helper defines
#undef WORST
#undef BAD
#undef NORMAL
#undef GOOD
#undef BEST

}  // namespace

namespace mon {

Effectiveness getEffectiveness(Element attackElement,
                               Element defenderElement) {
  return ELEMENT_EFFECTIVENESS[static_cast<unsigned int>(attackElement)]
                             [static_cast<unsigned int>(defenderElement)];
}

Effectiveness getEffectiveness(Family attackFamily, Family defenderFamily) {
  return FAMILY_EFFECTIVENESS[static_cast<unsigned int>(attackFamily)]
                             [static_cast<unsigned int>(defenderFamily)];
}

Element getElementFromString(const std::string& str) {
#define CHECK_ELEMENT_STR(elementStr) \
  if (str == #elementStr) {           \
    return mon::Element::elementStr;  \
  }
  // clang-format off
  CHECK_ELEMENT_STR(NONE)
  else CHECK_ELEMENT_STR(WATER)
  else CHECK_ELEMENT_STR(FIRE)
  else CHECK_ELEMENT_STR(ICE)
  else CHECK_ELEMENT_STR(WIND)
  else CHECK_ELEMENT_STR(AURA)
  else CHECK_ELEMENT_STR(POISON)
  else CHECK_ELEMENT_STR(ELEC)
  else CHECK_ELEMENT_STR(METAL)
  else CHECK_ELEMENT_STR(EARTH)
  else throw std::runtime_error("getElementFromString error: " + str +
                                " is not a valid Element value");
  // clang-format on
#undef CHECK_FAMILY_STR
}

Family getFamilyFromString(const std::string& str) {
#define CHECK_FAMILY_STR(familyStr) \
  if (str == #familyStr) {          \
    return mon::Family::familyStr;  \
  }
  // clang-format off
  CHECK_FAMILY_STR(NONE)
  else CHECK_FAMILY_STR(BIRD)
  else CHECK_FAMILY_STR(INSECT)
  else CHECK_FAMILY_STR(PLANT)
  else CHECK_FAMILY_STR(REPT)
  else CHECK_FAMILY_STR(BEAST)
  else CHECK_FAMILY_STR(DINO)
  else CHECK_FAMILY_STR(DRAGON)
  else throw std::runtime_error("getFamilyFromString error: " + str +
                                " is not a valid Family value");
  // clang-format on
#undef CHECK_FAMILY_STR
}

}  // namespace mon
