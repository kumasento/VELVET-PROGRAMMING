import java.util.Scanner;

public class prob1 {
    public static void main (String[] args) {
        int numLine;
        String str = "**********";
        Scanner in = new Scanner(System.in);

        do {
            System.out.println("Enter a line number:");
            numLine = in.nextInt();
            System.out.println("You entered number of lines: " + numLine);

            for (int curLine = 0; curLine < numLine; curLine ++) {
                String outputStr = str;
                for (int i = 0; i < curLine; i++)
                    outputStr = " " + outputStr;
                System.out.println(outputStr);
            }
        } while (in.hasNextLine());
    }
}
