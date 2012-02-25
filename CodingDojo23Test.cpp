#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)


void player_win(int & player1_score, int & player2_score, int player_number)
{
    if(player_number == 0)
        {
            player1_score = 15;
        }
    else
        {
            player2_score = 15;
        }
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player1_wins_then_15_0)
{
    int player1_score = 0;
    int player2_score = 0;
    player_win(player1_score, player2_score, 0);
    BOOST_CHECK(player1_score == 15);
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player2_wins_then_0_15)
{
    int player1_score = 0;
    int player2_score = 0;
    player_win(player1_score, player2_score, 1);
    BOOST_CHECK(player2_score == 15);
}

BOOST_AUTO_TEST_SUITE_END()

#undef BOOST_TEST_MODULE

