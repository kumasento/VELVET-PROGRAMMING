import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item [] itemlist;
    private int [] nextlist;
    private int [] prevlist;
    private boolean [] emptylist;
    private int N;
    private int front, rear;

    private int nextItem(int idx) { return nextlist[idx]; }
    private int prevItem(int idx) { return prevlist[idx]; }
    private boolean isEmptyItem(int idx) { return emptylist[idx]; }

    public RandomizedQueue() {
        itemlist = (Item []) new Object[2];
        nextlist = new int [2];
        prevlist = new int [2];
        emptylist = new boolean [2];
        front = 0;
        rear = 0;
    }
    public boolean isEmpty() { return (N == 0); }
    public int size() { return N; }

    private void resize(int capacity) {
        //good technique!
        //make sure the capacity is larger than the size of elements
        assert capacity >= N; 
        //Node<Item>[] tmp = (Node<Item>[]) new Object[capacity];
        Item[] tmpItem = (Item[]) new Object[capacity];
        int[] tmpNext = new int [capacity];
        int[] tmpPrev = new int [capacity];
        boolean[] tmpEmpty = new boolean [capacity];
        int tmpIdx = 0;
        for (int idx = front; idx < rear; idx = nextlist[idx]){
            tmpItem[tmpIdx] = itemlist[idx];
            tmpNext[tmpIdx] = tmpIdx+1;
            tmpPrev[tmpIdx] = tmpIdx-1;
            tmpEmpty[tmpIdx] = emptylist[idx];
            tmpIdx ++;
        }
        itemlist = tmpItem;
        nextlist = tmpNext;
        prevlist = tmpPrev;
        emptylist = tmpEmpty;
        front = 0;
        rear = N;
    }

    public void enqueue(Item item) {
        if (item == null) 
            throw new NullPointerException("intends to add a null item");
        if (rear == itemlist.length) 
            resize(itemlist.length * 2);
        itemlist[rear] = item;
        nextlist[rear] = rear + 1;
        if (rear == front) prevlist[rear] = -1; 
        else prevlist[rear] = rear - 1;
        emptylist[rear] = false;
        rear ++;
        N++;
    }

    private Item dequeueByIndex(int idx) {
        if (isEmptyItem(idx)) return null;
        int prevIdx = prevlist[idx];
        int nextIdx = nextlist[idx];
        
        if (nextIdx == rear && prevIdx == -1) { 
            rear = front;
        } else if (rear == nextIdx) {
            rear --;
            nextlist[prevIdx] = rear;
        } else if (prevIdx == -1){
            front = nextIdx;
            prevlist[nextIdx] = -1;
        } else {
            prevlist[nextIdx] = prevIdx;
            nextlist[prevIdx] = nextIdx;
        }

        emptylist[idx] = true;
        Item item = itemlist[idx];
        N--;
        if (N > 0 && N == (itemlist.length / 4)) 
            resize(itemlist.length/2);
        return item;
    }

    public Item dequeue() {
        if (isEmpty()) 
            throw new java.util.NoSuchElementException("intends to delete an item from an empty list");
        java.util.Random rdm = new java.util.Random(System.currentTimeMillis());
        int rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
        Item item = dequeueByIndex(rdIdx);
        while (item == null) {
            rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
            item = dequeueByIndex(rdIdx);
        }
        return item;
    }
    public Item sample() {
        if (isEmpty()) 
            throw new java.util.NoSuchElementException("intends to delete an item from an empty list");
        java.util.Random rdm = new java.util.Random(System.currentTimeMillis());
        int rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
        while (isEmptyItem(rdIdx))
            rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
        return itemlist[rdIdx];
    }
    public Iterator<Item> iterator() {
        return new NodeIter();
    }
    private class NodeIter implements Iterator<Item> {
        private boolean [] acc;
        private int top;

        public NodeIter() {
            acc = new boolean [itemlist.length];
            top = 0;
        }
        public boolean hasNext() {
            return top != N ;
        }
        public Item next() {
            if (!hasNext()) 
                throw new java.util.NoSuchElementException("out of bound");
        
            java.util.Random rdm = new java.util.Random(System.currentTimeMillis());
            int rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
            while (isEmptyItem(rdIdx) || acc[rdIdx]) 
                rdIdx = (int) Math.abs((long) rdm.nextInt()) % (rear - front) + front;
            Item item = itemlist[rdIdx];
            acc[rdIdx] = true;
            top++;
            return item;
        }
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
    
    private void printList() {
        StdOut.println("front: " + front + " rear: " + rear);
        for (int idx = 0; idx < itemlist.length; idx++) 
            StdOut.println(itemlist[idx] + " " + nextlist[idx] + " " + prevlist[idx] + " " + emptylist[idx]);
    }
    
    public static void main(String [] args) {
        RandomizedQueue<String> rq = new RandomizedQueue<String>();
        while (!StdIn.isEmpty()) {
            String token = StdIn.readString();
            if (token.equals("in")) {
                String paraToken = StdIn.readString();
                rq.enqueue(paraToken);
            } else if (token.equals("rm")) {
                String nextToken = StdIn.readString();
                int paraToken = StdIn.readInt();
                if (nextToken.equals("r")) StdOut.println(rq.dequeue());
                else if(nextToken.equals("l")) StdOut.println(rq.dequeueByIndex(paraToken));
            } else if (token.equals("sp")) {
                StdOut.println(rq.sample());
            } else if (token.equals("pl")) {
                rq.printList();
            } else if (token.equals("empty?")) {
                StdOut.println(rq.isEmpty());
            } else if (token.equals("size?")) {
                StdOut.println(rq.size());
            } else if (token.equals("show")) {
                for (String s : rq)
                       StdOut.print("["+s+"]");
                StdOut.print("\n");
            }   
        }
    }
}
