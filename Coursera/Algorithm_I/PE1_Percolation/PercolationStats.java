public class PercolationStats {
    private double [] prctArr;
    private double meanval;
    private double stddevval;
    private double confidenceLoval, confidenceHival;

    public PercolationStats(int N, int T) {
        if (N <= 0 || T <= 0) 
            throw new java.lang.IllegalArgumentException();

        prctArr = new double [T];
        java.util.Random rdm = new java.util.Random(Integer.MAX_VALUE);
        
        for (int i = 0; i < T; i++) {
            Percolation pc = new Percolation(N);
            boolean[][] rdc = new boolean [N+1][N+1];
            for (int x = 0; x <= N; x++) {
                for (int y = 0; y <= N; y++) {
                    rdc[x][y] = false;
                }
            }
            int cnt = 0;
            while (!pc.percolates()) {
                int rdi = (int) Math.abs((long) rdm.nextInt()) % N+1;
                int rdj = (int) Math.abs((long) rdm.nextInt()) % N+1;
                while (rdc[rdi][rdj]) {
                    rdi = (int) Math.abs((long) rdm.nextInt()) % N+1;
                    rdj = (int) Math.abs((long) rdm.nextInt()) % N+1;
                }
                rdc[rdi][rdj] = true;

                pc.open(rdi, rdj);
                cnt++;
            }
            prctArr[i] = cnt / (double) (N * N);
        }

        double sum = 0;
        for (int i = 0; i < T; i++)
            sum += prctArr[i];
        meanval = sum /(double) T;
        sum = 0;
        for (int i = 0; i < T; i++)
            sum += (prctArr[i] - meanval) * (prctArr[i] - meanval);
        stddevval = sum / (double) (T - 1);
        stddevval = Math.sqrt(stddevval);
        confidenceLoval = meanval - (1.96 * stddevval) / Math.sqrt(T);
        confidenceHival = meanval + (1.96 * stddevval) / Math.sqrt(T);
    }
    public double mean() {
        return meanval;
    }
    public double stddev() {
        return stddevval;
    }
    public double confidenceLo() {
        return confidenceLoval;
    }
    public double confidenceHi() {
        return confidenceHival;
    }
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);
        PercolationStats stats = new PercolationStats(N, T);
        StdOut.println("mean = " + stats.mean());
        StdOut.println("stddev = " + stats.stddev());
        StdOut.println("95%  confidence interval = " 
                        + stats.confidenceLo() + "," 
                        + stats.confidenceHi());
    }
}
