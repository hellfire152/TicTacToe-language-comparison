# Tic Tac Toe PYTHON

# numbers to present the 9 boxes in the tic tac toe grid
values = ['1', '2', '3', '4', '5', '6', '7', '8', '9']


# boolean representing the two players
player_one_turn = True


def display_board(board_values):
    print """
    {}|{}|{}
    {}|{}|{}
    {}|{}|{}
    """.format(*board_values)  # the * is the unpack operator


def has_winner(board_values):
    winning_char = 'X' if player_one_turn else 'O'
    win_message = "Player 1 wins!" if player_one_turn else "Player 2 wins!"
    # checking horizontals
    for i in range(0, 9, 3):
        for j in range(0, 3):
            if board_values[i + j] == winning_char:
                if j == 2:
                    print win_message
                    return True
                else:
                    continue
            else:
                break

    # checking verticals
    for i in range(0, 3):
        for j in range(0, 9, 3):
            if board_values[i + j] == winning_char:
                if j == 6:
                    print win_message
                    return True
                else:
                    continue
            else:
                break

    # chcking diagonals
    # left leaning
    for i in range(0, 9, 4):
        if board_values[i] == winning_char:
            if i == 8:
                print win_message
                return True
            else:
                continue
        else:
            break

    # right leaning
    for i in range(3, 8, 2):
        if board_values[i] == winning_char:
            if i == 6:
                print win_message
                return True
            else:
                continue
        else:
            break

# no main function in python, everything runs line by line
while True:
    turn_count = 0
    display_board(values)

    while True:
        input_no = None

        invalid_input = True
        while invalid_input:
            if player_one_turn:
                print "Player 1's turn: "
            else:
                print "Player 2's turn: "

            # various error checking
            try:
                input_no = int(input())
                if input_no < 1 or input_no > 9:
                    print "Please enter a number between 1 and 9!"
                    continue
                if values[input_no - 1] == 'X' or values[input_no - 1] == 'O':
                    print "Cell already occupied!"
                    continue
                # if no error
                values[input_no - 1] = 'X' if player_one_turn else 'O'
                turn_count += 1
                break
            except (TypeError, SyntaxError):
                print "Please enter a number between 1 and 9!"
                continue

        display_board(values)
        if has_winner(values):
            break
        if turn_count == 9:
            print "It's a draw!"
            break
        player_one_turn = not player_one_turn

    print "Play again? (y/n): "
    play_again_char = raw_input()
    if play_again_char == 'y':
        values = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}
        continue
    else:
        break
