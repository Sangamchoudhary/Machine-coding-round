#include<bits/stdc++.h>
using namespace std;

void print_board(vector<vector<char>> &board) {
	for (auto &it : board) {
		for (auto &i : it) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void players_input(unordered_map<char, string> &mp) {
	char ch; string name;
	cin >> ch >> name;
	mp[ch] = name;
	cin >> ch >> name;
	mp[ch] = name;
}

char check_win(vector<vector<char>> &board) {
	// row check
	for (auto &it : board) {
        int x = count(it.begin(), it.end(), 'X');
        int y = count(it.begin(), it.end(), 'Y');
		if (x == 3) return 'X';
		if (y == 3) return 'Y';
	}

	// column check
	for (int i = 0; i < 3; i++) {
		int ch1 = 0, ch2 = 0;
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X') ch1++;
			else if (board[i][j] == 'Y') ch2++;
		}
		if (ch1 == 3) return 'X';
		if (ch2 == 3) return 'Y';
	}

	// diagonal-1 check
	int ch1 = 0, ch2 = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][i] == 'X') ch1++;
		else if (board[i][i] == 'Y') ch2++;
	}

	if (ch1 == 3) return 'X';
	if (ch2 == 3) return 'Y';

	//diagonal2 - check
	ch1 = 0, ch2 = 0;
	int i = 0, j = 2;
	while (i < 3) {
		if (board[i][j] == 'X') ch1++;
		else if (board[i][j] == 'Y') ch2++;
		i++, j--;
	}

	if (ch1 == 3) return 'X';
	if (ch2 == 3) return 'Y';

	return 'Z';
}

bool board_full(vector<vector<char>> &board) {
	int x = 0, y = 0;
	for (auto &it : board) {
		x += count(it.begin(), it.end(), 'X');
		y += count(it.begin(), it.end(), 'Y');
	}
	if (x + y == 9) return true;
	return false;
}

int main() {
    // Game start

	//player entry
	unordered_map<char, string> mp;
	players_input(mp);

	// initial board
	vector<vector<char>> board(3, vector<char> (3, '-'));
	print_board(board);

	// take positions
	// true for 1st player, false for 2nd player
	bool player = true;

	char ch1, ch2;
	while (true) {
		cin >> ch1 >> ch2;
		if (ch1 == 'e') break;

		// taking cordinates
		int i = (ch1 - '0') - 1, j = (ch2 - '0') - 1;

		// Invalid Move condition
		//---> condn 1
		if (i >= 3 or j >= 3 or i < 0 or j < 0) {
			cout << "Invalid Move"; continue;
		}
		//---> condn 2
		if (board[i][j] != '-') {
			cout << "Invalid Move"; continue;
		}

		// filling the board with cross or zero
		board[i][j] = player ? 'X' : 'Y';
		player = !player; // changing player turn
        print_board(board);

		// check if anyone is winner or not
		char winner = check_win(board);
		print_board(board);

		// if winner then announce his/her name
		if (winner == 'X') {
			cout << mp['X'] << " won the game";
			break;
		}
		else if (winner == 'Y') {
			cout << mp['Y'] << " won the game";
			break;
		}

		// Game over case
		if (board_full(board)) {
			cout << "Game Over"; break;
		}
	}

}
