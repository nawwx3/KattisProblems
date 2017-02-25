import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
 * Created by Nathan Welch on 2/23/2017.
 * Watering Grass - https://open.kattis.com/problems/grass
 */
public class main{
    /* greedy approach
       sort into array with least l in front
     */

    public static void main(String[] args) throws IOException{
        File folder = new File("input.txt");
        Scanner scanner = new Scanner(folder);
        // while not end of file, loop all this stuff
        while(scanner.hasNext()) {
            ArrayList<Point> points = new ArrayList<>();
            numS n = new numS(); //number of sprinklers
            Length l = new Length();
            Width w = new Width();

            //read in inputs of first case
            n.setN(scanner.nextInt());
            l.setL(scanner.nextInt());
            w.setW(scanner.nextInt());

            for(int i = 0; i < (n.getN()); i++) {
                /** have to make NEW point for each iteration then insert the point into the arrayList
                 NEW point is why this is here and not outside the loop
                 if outside, it makes 1 and adds it multiple times instead of
                 a NEW point for each place in the ArrayList
                 */
                Point temp = new Point();
                temp.setX(scanner.nextInt());
                temp.setRadius(scanner.nextInt());
                points.add(i, temp);
                }

            System.out.println(n.getN() + ", " + l.getL() + ", " + w.getW());


            //sort the list based on 'radius'
            Collections.sort(points, new PointComparatorByR());

          //do greedy algorithm
            //create Solutions ArrayList
            ArrayList<Point> Solution = new ArrayList<>();
            if(Solution.size() == 0) {
                Solution.add(points.get(0));
            }
            else {
                //1 because first is being inserted when Solution is empty
                for(int i = 1; i < (n.getN()); i++) {
                    if(!overlap(Solution, points, i)) { //if the don't overlap put current point check in solution
                        Point temp = new Point();
                        temp.setX(1);
                        temp.setRadius(1);
                        Solution.add(i, temp);
                    }
                }

            }

            //print out array ->  won't need this in then end
            /**  for(int i = 0; i < points.size(); i++) {
             System.out.println(points.get(i).getX() + ", " + points.get(i).getRadius());
             }
             these do the same thing.  Below is a "for each" loop
             these are best used with arrays -  also called an "enhanced for loop"
             single iteration of : this element                   */
            for (Point point: points) {
                System.out.println(point.getX() + ", " + point.getRadius());
            }

            System.out.print("Solution:  ");
            for (Point Solutions: Solution) {
                System.out.print("(" + Solutions.getX() + ", " + Solutions.getRadius() + ")");
            }
            System.out.println();


            need to set bounds for each of the inputs


        }
        scanner.close();
    }//end main()


    public static boolean overlap(ArrayList<Point> Solution, ArrayList<Point> points, int pind) {
        boolean overlap = false;
        //if the current from points overlaps (does not contribute to) Solution
        //      -> return true -> does overlap

        /*  need all of solution (have to check against whole thing)
            need the Point checking against
                -> ArrayList it's in
                -> It's location in ArrayList
         */

        /*  area of circle inside the square
            not being taken up by other circles
            if zero
                -> return false

         */



        return overlap;
    }

}//end file



class PointComparatorByR implements Comparator<Point> {
    //http://stackoverflow.com/questions/24975167/java-how-to-use-compareto-to-sort-an-arraylist
    @Override
    public int compare(Point p1, Point p2) {
        return p2.getRadius() - p1.getRadius();
    }
}

class Length {
    private int length;

    public Length() {
        length = 0;
    }

    public int getL() { return length; }
    public void setL(int length) {
        this.length = length;
    }
}
class Width {
    private int width;

    public Width() {
        width = 0;
    }

    public int getW() { return width; }
    public void setW(int width) {
        this.width = width;
    }
}

class numS {
    private int nums;

    public numS() {
        nums = -1;
    }

    public int getN() { return nums; }
    public void setN(int nums) {
        this.nums = nums;
    }
}

class Point {
    private int x;
    private int radius;

    public Point() {
        x = 0;
        radius = 0;
    }

    public int getX() { return x; }
    public void setX(int pos) { x = pos; }

    public int getRadius() { return radius; }
    public void setRadius(int rad) { radius = rad; }

}