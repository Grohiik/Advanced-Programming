import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    private static int read_maze(String[] matrix, int[][] nodes, int heigth,
                                 int width, Scanner scanner) {
        int num_nodes = 0;
        for (int i = 0; i < heigth; i++) {
            matrix[i] = scanner.nextLine();
            for (int ii = 0; ii < width; ii++) {
                if (matrix[i].charAt(ii) == 'A' ||
                    matrix[i].charAt(ii) == 'S') {
                    nodes[num_nodes][0] = i;
                    nodes[num_nodes][1] = ii;
                    nodes[num_nodes++][2] = 0;
                }
            }
        }

        return num_nodes;
    }

    private static int BFS(String[] maze, int width, int heigth, int[] start,
                           int[] end) {
        int[][] delta_list = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start.clone());
        while (!queue.isEmpty()) {
            int[] current_node = queue.remove();
            if (current_node[0] == (end[0]) && current_node[1] == end[1]) {
                return current_node[2];
            }
            for (int[] delta : delta_list) {
                if (maze[current_node[0] + delta[0]].charAt(current_node[1] +
                                                            delta[1]) != '#') {
                    int[] temp = {current_node[0] + delta[0],
                                  current_node[1] + delta[1],
                                  current_node[2] + 1};
                    queue.add(temp);
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        scanner.nextLine();
        while (cases-- > 0) {
            int width = scanner.nextInt();
            int heigth = scanner.nextInt();
            String[] maze = new String[heigth];
            int[][] nodes = new int[200][3];
            int num_nodes = read_maze(maze, nodes, heigth, width, scanner);
        }

        scanner.close();
    }
}