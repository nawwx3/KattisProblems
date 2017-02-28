import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/*
 * Created by Nathan Welch on 2/23/2017.
 * Watering Grass - https://open.kattis.com/problems/grass
 * Got help from here - https://algorithmcafe.wordpress.com/2011/10/03/10382-watering-grass/
 */
public class main{
    /* greedy approach
       sort into array with least l in front
     */

    public static void main(String[] args) throws IOException{

        InputStreamReader streamReader = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(streamReader);
        //instead of inputting from a file, input as it were a file being piped in

        while(true) {
            String line = reader.readLine(); //reads input as a string
            if(line == null)  //if end of file, exit the loop
                break;

            String[] in = line.split(" "); //split the input when a " " is reached
            int n = Integer.parseInt(in[0]); //takes the first split from previous line and assigns it to 'n'
            int l = Integer.parseInt(in[1]); //takes the second split from previous line and assigns it to 'l'
            double w = Integer.parseInt(in[2]); //takes the third split from previous line and assigns it to 'w'

            //array keeping track of start and stop points of circle (sprinklers) inside the square (grass)
            ArrayList<areaCovered> ac = new ArrayList<>();

            for(int i = 0; i < n; i ++) {
                //for each sprinkler input, calculate the start and end points where the sprinkler
                //is touching the edge of the grass
                in = reader.readLine().split(" "); //same as before
                double x = Integer.parseInt(in[0]);
                double r = Integer.parseInt(in[1]);

                double xVal = Math.sqrt(r*r - w*w/4);
                //puts inputs into a list

                /** have to make NEW point for each iteration then insert the point into the arrayList
                 NEW point is why this is here and not outside the loop
                 if outside, it makes 1 and adds it multiple times instead of
                 a NEW point for each place in the ArrayList
                 */
                areaCovered temp = new areaCovered();
                temp.setStart(x-xVal); //x-coord - distance to circle_square intersection
                temp.setEnd(x+xVal); //x-coord + distance to circle_square intersection
                ac.add(temp); //add temp into the ArrayList
            }

            //sort the list based on first ac encountered
            Collections.sort(ac, new areaCovered());

            //do greedy algorithm
            //create Solutions ArrayList
            ArrayList<areaCovered> Solution = new ArrayList<>();
            int i = 0;
            int j;
            double end = 0;    //end of accepted length of sprinklers
            boolean check = true;
            double max;
            while(end < l && check) {   //while haven't reached and there are still acceptable inputs
                check = false;
                max = end;
                //iterates when not at the end of inputs and start_value of current sprinkler is less than end of grass
                for(j = i; j < n && ac.get(j).getStart() <= end; j++) {
                    check = true;
                   if(ac.get(j).getEnd() > max) //if end_range of current sprinkler is greater than area of square covered
                       max = ac.get(j).getEnd(); //make new max
                }
                if(end != max)     //if new sprinkler was added
                    Solution.add(ac.get(i));  //add it
                end = max;
                i = j;
            }
            if(!check)
                System.out.println("-1");
            else
                System.out.println(Solution.size());
        }
    }//end main()

//            print out array ->  won't need this in then end
/**              for(int i = 0; i < points.size(); i++) {
                     System.out.println(points.get(i).getX() + ", " + points.get(i).getRadius());
                 }
             these do the same thing.  Below is a "for each" loop
             these are best used with arrays -  also called an "enhanced for loop"

//             single iteration of : this element                   */
//            for (areaCovered acs: ac) {
//                System.out.println("(" + acs.getStart() + ", " + acs.getEnd() + ")");
//            }
}//end file

class areaCovered implements Comparator<areaCovered> {
    double start;
    double end;

    public areaCovered() {
        start = 0;
        end = 0;
    }

    public int compare(areaCovered a1, areaCovered a2) {
        return (int) (a1.getStart() - a2.getStart());
    }

    public double getStart() { return start; }
    public void setStart(double s) { this.start = s; }

    public double getEnd() { return end; }
    public void setEnd(double e) { this.end = e; }
}
