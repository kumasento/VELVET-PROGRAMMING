import java.util.Iterator;

public class Deque<Item> implements Iterable<Item>{
    private Node<Item> first, last;
    private int size;

    private class Node<Item>{
        Node<Item> prev, next;
        Item item;
    }

    public Deque(){
        first = last = null;
        size = 0;
    }
    public boolean isEmpty() {
        return (size == 0); 
    }
    public int size() {
        return size;
    }
    public void addFirst(Item item) {
        if (item == null) 
            throw new NullPointerException("intends to add a null item");        
        if (isEmpty()) {
            first = new Node<Item>();
            first.item = item;
            first.next = first.prev = null;
            last = first;
        } else {
            Node<Item> oldfirst = first;
            first = new Node<Item>();
            first.item = item;
            first.next = oldfirst;
            first.prev = null;
            oldfirst.prev = first;
        }
        size ++;
    }
    public void addLast(Item item) {
        if (item == null) 
            throw new NullPointerException("intends to add a null item");
        if (isEmpty()) {
            last = new Node<Item>();
            last.item = item;
            last.next = last.prev = null;
            first = last;
        } else {
            Node<Item> oldlast = last;
            last = new Node<Item>();
            last.item = item;
            last.prev = oldlast;
            last.next = null;
            oldlast.next = last;
        }
        size ++;
    }
    public Item removeFirst() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("intends to remove an element from an empty deque");

        Item item = first.item;
        if (size == 1) 
            first = last = null;
        else {
            first.prev = null;
            first = first.next;
        }
        size--;
        return item;
    }
    public Item removeLast() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("intends to remove an element from an empty deque");
        
        Item item = last.item;
        if (size == 1) 
            first = last = null;
        else {
            last = last.prev;
            last.next = null;
        }
        size --;
        return item;
    }

    private class NodeIter<Item> implements Iterator<Item> {
        private Node<Item> current;
        public NodeIter(Node<Item> first) {
            current = first;
        }
        public boolean hasNext() {
            return current != null ;
        }
        public Item next() {
            if (!hasNext()) 
                throw new java.util.NoSuchElementException("out of bound");
        
            Item item = current.item;
            current = current.next;
            return item;
        }
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public Iterator<Item> iterator() {
        return new NodeIter<Item>(first);
    }

    public static void main(String [] args) {
        Deque<String> strdeque = new Deque<String>();
        String token, nextToken, paraToken;
        while (!StdIn.isEmpty()) {
            token = StdIn.readString();
            if (token.equals("add")) {
                nextToken = StdIn.readString();
                paraToken = StdIn.readString();
                if (nextToken.equals("f")) strdeque.addFirst(paraToken);
                else if (nextToken.equals("l")) strdeque.addLast(paraToken);
            } else if (token.equals("rm")) {
                nextToken = StdIn.readString();
                if (nextToken.equals("f")) StdOut.println(strdeque.removeFirst());
                else if(nextToken.equals("l")) StdOut.println(strdeque.removeLast());
            } else if (token.equals("empty?")) {
                StdOut.println(strdeque.isEmpty());
            } else if (token.equals("size?")) {
                StdOut.println(strdeque.size());
            } else if (token.equals("show")) {
                for (String s : strdeque)
                       StdOut.print("["+s+"]");
                StdOut.print("\n");
            }   
        }
    }
}

