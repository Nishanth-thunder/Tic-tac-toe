# define new board.
board = [' ' for x in range(10)]

# insertLetter: function to insert 'X' or 'O' the value of board base on position, param: Letter= 'X' or 'O' sign, pos= position on the board. 
def insertLetter(letter, pos):
    board[pos] = letter

# spaceIsFree: function to refresh the value of board base on position, param: pos= position on the board. 
def spaceIsFree(pos):
    return board[pos] == ' '
 
# printBoard: function to print new board to the screen, param: board= the board itself.
def printBoard(board):
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')

# isWinner: function to check that in board whether 'X' or 'O' sign completed in board, param: bo= 'X' or 'O' sign, le= 'X' or 'O' sign.    
def isWinner(bo, le):
    return (bo[7] == le and bo[8] == le and bo[9] == le) or (bo[4] == le and bo[5] == le and bo[6] == le) or(bo[1] == le and bo[2] == le and bo[3] == le) or(bo[1] == le and bo[4] == le and bo[7] == le) or(bo[2] == le and bo[5] == le and bo[8] == le) or(bo[3] == le and bo[6] == le and bo[9] == le) or(bo[1] == le and bo[5] == le and bo[9] == le) or(bo[3] == le and bo[5] == le and bo[7] == le)

# compMove: function that will run if is player turn that to place 'X' in board. 
def playerMove():
    run = True
    while run:
        move = input('Please select a position to place an \'X\' (1-9): ')
        try:
            move = int(move)
            if move > 0 and move < 10:
                if spaceIsFree(move):
                    run = False
                    insertLetter('X', move)
                else:
                    print('Sorry, this space is occupied!')
            else:
                print('Please type a number within the range!')
        except:
            print('Please type a number!')
            
# compMove: function that will run if is computer turn that to place 'O' in board. 
def compMove():
    possibleMoves = [x for x, letter in enumerate(board) if letter == ' ' and x != 0]
    move = 0
    count =0
    place=0
    for x in range (10):
      if board[x]==' 'and x!=0:
          count+=1
    if count==8 :
      for x in range(10):
        if board[x]=='X'and x!=0:
          if x==1 or x==3 or x==7 or x==9:
            move=5
          if x==5:
            move =selectRandom([1,3,7,9])
          if x==2 or x==4 or x==6 or x==8:
            break
          return move 
    
    
    for let in ['O', 'X']:
        for i in possibleMoves:
            boardCopy = board[:]
            boardCopy[i] = let
            if isWinner(boardCopy, let):
                move = i
                return move
 
    cornersOpen = []
    for i in possibleMoves:
        if i in [1,3,7,9]:
            cornersOpen.append(i)
            
    if len(cornersOpen) > 0:
        move = selectRandom(cornersOpen)
        return move
 
    if 5 in possibleMoves:
        move = 5
        return move
 
    edgesOpen = []
    for i in possibleMoves:
        if i in [2,4,6,8]:
            edgesOpen.append(i)
            
    if len(edgesOpen) > 0:
        move = selectRandom(edgesOpen)
        
    return move

# selectRandom: function that player 'O' (computer) to select randomly place the O in the board, param: li= list of number position in the board.
def selectRandom(li):
    import random
    ln = len(li)
    r = random.randrange(0,ln)
    return li[r]
    
# isBoardFull: function to check whether the board is full or not base on the board contain space > 1 or not, if right return true else false.
# param: board= the board itself.
def isBoardFull(board):
    if board.count(' ') > 1:
        return False
    else:
        return True

# Main Function: first function that will run in this game. the function will define the board, player 'O', and player 'X'.
# the function also check whether the board full and player 'O' win, or the board full and player 'X' win, or the game tie.
# and if the game is finished the program will ask the player "Do you want to play again? (Y/N)" and yes to play else to end the game. 
def main():
    print('Welcome to Tic Tac Toe!')
    printBoard(board)
 
    while not(isBoardFull(board)):
        if not(isWinner(board, 'O')):
            playerMove()
            printBoard(board)
        else:
            print('Sorry, O\'s won this time!')
            break
 
        if not(isWinner(board, 'X')):
            move = compMove()
            if move == 0:
                print('Tie Game!')
            else:
                insertLetter('O', move)
                print('Computer placed an \'O\' in position', move , ':')
                printBoard(board)
        else:
            print('X\'s won this time! Good Job!')
            break
 
    if isBoardFull(board):
        print('Tie Game!')
 
while True:
    answer = input('Do you want to play again? (Y/N)')
    if answer.lower() == 'y' or answer.lower == 'yes':
        board = [' ' for x in range(10)]
        print('-----------------------------------')
        main()
    else:
        break
