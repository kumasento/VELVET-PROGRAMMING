class Student {
    public String id;
    public String name;
    public double foreign_grade;
    public double advmath_grade;
    public double politic_grade;

    public Student(String id, String name, double f_grade, double a_grade, double p_grade) {
        this.id = id;
        this.name = name;
        this.foreign_grade = f_grade;
        this.advmath_grade = a_grade;
        this.politic_grade = p_grade;
    }

    public boolean isPassed() {
        return (this.foreign_grade >= 60 &&
                this.advmath_grade >= 60 &&
                this.politic_grade >= 60);
    }
}

public class prob2 {
    public static void main(String[] args) {
        Student [] students = new Student [5];
        students[0] = new Student("1", "fail_student_1", 60.0, 59.0, 40.0);
        students[1] = new Student("2", "pass_student_2", 60.0, 60.0, 90.0);
        students[2] = new Student("3", "fail_student_3", 60.0, 59.0, 61.0);
        students[3] = new Student("4", "fail_student_4", 55.0, 59.0, 40.0);
        students[4] = new Student("5", "pass_student_5", 60.0, 60.0, 60.0);

        for (int i = 0; i < 5; i++) {
            if (students[i].isPassed()) {
                System.out.println("Student ID: "
                        + students[i].id
                        + " Name: "
                        + students[i].name);
            }
        }
    }
}
