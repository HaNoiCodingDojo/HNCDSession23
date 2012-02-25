#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

void player1_win(int & player1_score, int & player2_score)
{
    player1_score = 15;
}

void player2_win(int & player1_score, int & player2_score)
{
    player2_score = 15;
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player1_wins_then_15_0)
{
    int player1_score = 0;
    int player2_score = 0;
    player1_win(player1_score, player2_score);
    BOOST_CHECK(player1_score == 15);
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player2_wins_then_0_15)
{
    int player1_score = 0;
    int player2_score = 0;
    player2_win(player1_score, player2_score);
    BOOST_CHECK(player2_score == 15);
}

BOOST_AUTO_TEST_SUITE_END()

#undef BOOST_TEST_MODULE

