#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

#define PLAYER1 0
#define PLAYER2 1

void increase_score(int & player_score)
{
    int advantage = 50;
    if (player_score == 30)
        {
            player_score += 10;
        }
    else if (player_score <= 15)
        {
            player_score += 15;
        }
    else if (player_score == 40)
        {
            player_score = advantage;
        }
    if (player_score == advantage)
        {
            player_score = 40;
        }
}

void player_win(int & player1_score, int & player2_score, int player_number)
{
    if(player_number == PLAYER1)
        {
            increase_score(player1_score);
        }
    else if (player_number == PLAYER2)
        {
            increase_score(player2_score);
        }
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player1_wins_then_15_0)
{
    int player1_score = 0;
    int player2_score = 0;
    player_win(player1_score, player2_score, PLAYER1);
    BOOST_CHECK(player1_score == 15);
}

BOOST_AUTO_TEST_CASE(score_is_0_0_player2_wins_then_0_15)
{
    int player1_score = 0;
    int player2_score = 0;
    player_win(player1_score, player2_score, PLAYER2);
    BOOST_CHECK(player2_score == 15);
}


BOOST_AUTO_TEST_CASE(score_is_15_0_player1_wins_then_30_0)
{
    int player1_score = 15;
    int player2_score = 0;
    player_win(player1_score, player2_score, PLAYER1);
    BOOST_CHECK(player1_score == 30);
    BOOST_CHECK(player2_score == 0);
}


BOOST_AUTO_TEST_CASE(score_is_0_15_player2_wins_then_0_30)
{
    int player1_score = 0;
    int player2_score = 15;
    player_win(player1_score, player2_score, PLAYER2);
    BOOST_CHECK(player1_score == 0);
    BOOST_CHECK(player2_score == 30);
}

BOOST_AUTO_TEST_CASE(score_is_15_15_player1_wins_then_30_15)
{
    int player1_score = 15;
    int player2_score = 15;
    player_win(player1_score, player2_score, PLAYER1);
    BOOST_CHECK(player1_score == 30);
    BOOST_CHECK(player2_score == 15);
}

BOOST_AUTO_TEST_CASE(score_is_30_0_player1_wins_then_40_0)
{
    int player1_score = 30;
    int player2_score = 0;
    player_win(player1_score, player2_score, PLAYER1);
    BOOST_CHECK(player1_score == 40);
    BOOST_CHECK(player2_score == 0);
}

BOOST_AUTO_TEST_CASE(score_is_0_30_player2_wins_then_0_40)
{
    int player1_score = 0;
    int player2_score = 30;
    player_win(player1_score, player2_score, PLAYER2);
    BOOST_CHECK(player1_score == 0);
    BOOST_CHECK(player2_score == 40);
}

BOOST_AUTO_TEST_CASE(score_is_40_40_player1_wins_then_A_40)
{
    int player1_score = 40;
    int player2_score = 40;
    int advantage = 50;
    player_win(player1_score, player2_score, PLAYER1);
    BOOST_CHECK(player1_score == advantage);
    BOOST_CHECK(player2_score == 40);
}

BOOST_AUTO_TEST_CASE(score_is_A_40_player2_wins_then_40_40)
{
    int advantage = 50;
    int player1_score = advantage;
    int player2_score = 40;
    player_win(player1_score, player2_score, PLAYER2);
    BOOST_CHECK(player1_score == 40);
    BOOST_CHECK(player2_score == 40);
}

BOOST_AUTO_TEST_SUITE_END()

#undef BOOST_TEST_MODULE

