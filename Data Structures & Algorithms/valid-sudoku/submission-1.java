class Solution {
    public boolean isValidSudoku(char[][] board) {
        Map<Integer, Set<Character> > cols = new HashMap<>();
        Map<Integer, Set<Character> > rows = new HashMap<>();
        Map<String, Set<Character> > box = new HashMap<>();

        String squareKey;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                continue;

                squareKey = (i/3) + "," + (j/3); 
                if(rows.computeIfAbsent(i, k->new HashSet<>()).contains(board[i][j]))
                return false;

                if(cols.computeIfAbsent(j, k->new HashSet<>()).contains(board[i][j]))
                return false;

                if(box.computeIfAbsent(squareKey, k->new HashSet<>()).contains(board[i][j]))
                return false;

                rows.get(i).add(board[i][j]);
                cols.get(j).add(board[i][j]);
                box.get(squareKey).add(board[i][j]);
            }
        }

        return true;
    }
}
