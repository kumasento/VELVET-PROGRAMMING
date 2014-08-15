public class Board {
    private int N;
    private int [][] blocks;

    public Board(int[][] blocks) {
        N = blocks[0].length;
        this.blocks = new int[N][N];
        
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                this.blocks[i][j] = blocks[i][j];
    }
    public int dimension() { return N; }
    public int hamming() {
        int dist = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int idx = (i*N+j+1) % (N*N);
                dist += (idx != blocks[i][j]) ? 1 : 0;
            }

        return dist;
    }
    public int manhattan() {
        int dist = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int pos = blocks[i][j];
                int pos_x, pos_y;
                if (pos == 0) pos_x = pos_y = 2;
                else {
                    pos_x = (pos-1) / N;
                    pos_y = (pos-1) % N;
                }
                int h = Math.abs(pos_x - i);
                int v = Math.abs(pos_y - j);
                dist += h + v;
            }
        return dist;
    }
    public boolean isGoal() { return hamming() == 0; }
    public Board twin() {
        int[][] twinblocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) 
                twinblocks[i][j] = blocks[i][j];
        int idx = 0, val = -1;
        for (int i = 0; i < N; i++){
            if (twinblocks[0][i] != 0) {
                if (idx != 0) {
                    twinblocks[0][idx] = twinblocks[0][i];
                    twinblocks[0][i] = val;
                    break;
                }
                else{
                    idx = i;
                    val = twinblocks[0][i];
                }
            }
        }
        Board twinBoard = new Board(blocks);
        return twinBoard;
    }
    public boolean equals(Object y) {
        if (y == this) return true;
        if (y == null) return false;
        if (y.getClass() != this.getClass()) return false;
        Board that = (Board) y;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                if (this.blocks[i][j] != that.blocks[i][j])
                    return false;
        return true;
    }
    public Iterable<Board> neighbors() {
        int x = 0, y = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (blocks[i][j] == 0) 
                    x = i, y = j;


    }

    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);
    
        StdOut.println(initial.hamming());
        StdOut.println(initial.manhattan());
        StdOut.println(initial.isGoal());
        StdOut.println(initial.equals(initial));
    }
}
