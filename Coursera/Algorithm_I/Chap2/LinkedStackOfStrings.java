public class LinkedStackOfStrings {
    private class Node {
        String item;
        Node next;
    }
    
    private Node first = null;

    public boolean isEmpty()
    { return first == null; }

    public void push(String item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
    }

    public String pop() {
        String item = first.item;
        first = first.next;
        return item;
    }

    public static void main(String [] args) {
        LinkedStackOfStrings stack = new LinkedStackOfStrings();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (item.equals("-")) StdOut.println(stack.pop());
            else stack.push(item);
        }
    }
}
