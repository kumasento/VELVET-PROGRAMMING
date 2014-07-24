public class Percolation
{
    private int size;
    private int width;
    private boolean [] isOpenArr;
    private WeightedQuickUnionUF quickFindUF, quickFindUF2;

    public Percolation(int N)
    {  
        if (N <= 0)
            throw new java.lang.IllegalArgumentException();
        width = N;
        size = N * N;
        isOpenArr = new boolean[size+1];
        // first element is for node top, last element is for node bottom
        quickFindUF = new WeightedQuickUnionUF(size+1);
        quickFindUF2 = new WeightedQuickUnionUF(size+2);

        for (int i = 0; i <= size; i++)
            isOpenArr[i] = false;
    }

    private int convertToIndex(int i, int j)
    {
        if (i <= 0 || i > width) 
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j <= 0 || j > width) 
            throw new IndexOutOfBoundsException("column index j out of bounds");

        return (i - 1) * width + j;
    }


    public void open(int i, int j)
    { // open site (row i, column j) if it is not already
        int idx = convertToIndex(i, j);
        isOpenArr[idx] = true;

        //Here to union elements
        //When N = 1, i == 1 && i == width
        if (i == 1) {
            quickFindUF.union(0, idx);
            quickFindUF2.union(0, idx);
        }
        if (i == width)
            quickFindUF2.union(idx, size+1);

        if (i-1 != 0 && isOpen(i-1, j)) {
            quickFindUF.union(idx, convertToIndex(i-1, j));
            quickFindUF2.union(idx, convertToIndex(i-1, j));
        }
        if (j-1 != 0 && isOpen(i, j-1)) {
            quickFindUF.union(idx, convertToIndex(i, j-1));
            quickFindUF2.union(idx, convertToIndex(i, j-1));
        }
        if (i != width && isOpen(i+1, j)) {
            quickFindUF.union(idx, convertToIndex(i+1, j));
            quickFindUF2.union(idx, convertToIndex(i+1, j));
        }
        if (j != width && isOpen(i, j+1)) {
            quickFindUF.union(idx, convertToIndex(i, j+1));
            quickFindUF2.union(idx, convertToIndex(i, j+1));
        }
    }

    public boolean isOpen(int i, int j)
    {    // is site (row i, column j) open?
        return isOpenArr[convertToIndex(i, j)];
    }
    public boolean isFull(int i, int j)
    {    // is site (row i, column j) full?
        return isOpen(i, j) 
            && quickFindUF.connected(convertToIndex(i, j), 0);
    }
    public boolean percolates()
    {           
        return quickFindUF2.connected(size+1, 0);
    }

    public static void main(String [] args) {
        int N = StdIn.readInt();
        Percolation pc = new Percolation(N);

        while (!StdIn.isEmpty()) {
            int i = StdIn.readInt();
            int j = StdIn.readInt();

            pc.open(i, j);

            StdOut.println(pc.isFull(i, j));
            StdOut.println(pc.percolates());
        }
    }
}

