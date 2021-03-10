#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {

    CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )")); // Russian Hat
    CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )")); // Fez
    CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )")); // Mexican Hat
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Straw Hat

    //left eye options
    CHECK((snowman(11114411)) == ("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK((snowman(21214343)) == ("\n  ___ \n .....\n (o,.)\n (   )\\\n (___)\n"));
    CHECK((snowman(44332211)) == ("\n  ___\n (_*_)\n\\(O O)/\n ( : )\n ( : )\n"));
    CHECK((snowman(33421122)) == ("\n   _\n  /_\\ \n (-_o)\n>(] [)<\n (\" \")\n"));
    
    //nose/mouth
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));

    CHECK(nospaces(snowman(11111121)) == nospaces("_===_\n(.,.)\n<(] [)>\n( : )")); // Torso - Vest
    CHECK(nospaces(snowman(11111141)) == nospaces("_===_\n(.,.)\n<(   )>\n( : )")); // None
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // Torso - Buttons
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n(.,.)\n<(> <)>\n( : )")); // Torso - Inward Arms
    
}

TEST_CASE("Bad snowman code") {
    
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(11191231));
    CHECK_THROWS(snowman(11191991));
    CHECK_THROWS(snowman(11191111));
    CHECK_THROWS(snowman(111312412));
    CHECK_THROWS(snowman(111352412));
    CHECK_THROWS(snowman(11035241));
    CHECK_THROWS(snowman(11031241));
    CHECK_THROWS(snowman(-11191231));
    CHECK_THROWS(snowman(231));
    CHECK_THROWS(snowman(000));
}



