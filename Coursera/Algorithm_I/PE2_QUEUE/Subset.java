public class Subset {
    public static void main(String[] args){
        int k = Integer.parseInt(args[0]);
        RandomizedQueue<String> rq = new RandomizedQueue<String>();
        while (!StdIn.isEmpty()) 
            rq.enqueue(StdIn.readString());
        java.util.Iterator<String> iter = rq.iterator();
        for (int idx = 0; idx < k; idx ++) {
            StdOut.println(iter.next());
        }
    }
}
