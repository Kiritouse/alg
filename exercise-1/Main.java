import java.util.*;

public class Main {
    public static int findMinNotInS(int a, int b, int m, int s0) {
        TreeMap<Integer, Integer> map_int = new TreeMap<>();
        int sn = s0;
        while (true) {
            map_int.put(sn, map_int.getOrDefault(sn, 0) + 1);
            if (map_int.get(sn) == 2) {
                break;
            }
            sn = (a * sn + b) % m;
        }
        int i = 0;
        while(true){
            if(map_int.getOrDefault(i, 0) == 0) return i;
            i++;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int m = scanner.nextInt();
            System.out.println(findMinNotInS(a, b, m, 0));
        }
        scanner.close();
    }
}