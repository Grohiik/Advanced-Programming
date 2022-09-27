import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

class Killing_Aliens_in_Borg_maze {
    private static int read_maze(String[] matrix, int[][] nodes, int heigth,
                                 int width, Scanner scanner) {
        int num_nodes = 0;
        for (int i = 0; i < heigth; i++) {
            matrix[i] = scanner.nextLine();
            for (int ii = 0; ii < matrix[i].length(); ii++) {
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
        int[][] visited = new int[heigth][width];
        int[][] delta_list = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start.clone());
        while (!queue.isEmpty()) {
            int[] current_node = queue.remove();
            if (current_node[0] == (end[0]) && current_node[1] == end[1]) {
                return current_node[2];
            }
            for (int[] delta : delta_list) {
                int x = current_node[0] + delta[0];
                int y = current_node[1] + delta[1];
                if (maze[x].charAt(y) != '#' && visited[x][y] == 0) {
                    visited[x][y] = 1;
                    int[] temp = {x, y, current_node[2] + 1};
                    queue.add(temp.clone());
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    private static int prim(int[][] distance_matrix) {
        if (distance_matrix.length <= 0) return 0;
        int[] node_weights = new int[distance_matrix.length];
        for (int i = 0; i < distance_matrix.length; i++) {
            node_weights[i] = -1;
        }

        PriorityQueue<int[]> queue = new PriorityQueue<>(
            distance_matrix.length, new Comparator<int[]>() {
                public int compare(int[] val1, int[] val2) {
                    if (val1[1] > val2[1]) return 1;
                    if (val2[1] > val1[1]) return -1;
                    return 0;
                }
            });
        int[] temp = {0, 0};
        queue.add(temp.clone());

        while (!queue.isEmpty()) {
            int[] current_node = queue.remove();
            if (node_weights[current_node[0]] < 0) {
                node_weights[current_node[0]] = current_node[1];

                for (int i = 0; i < distance_matrix.length; i++) {
                    temp[0] = i;
                    temp[1] = distance_matrix[current_node[0]][i];
                    queue.add(temp.clone());
                }
            }
        }
        return Arrays.stream(node_weights).sum();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        scanner.nextLine();
        while (cases-- > 0) {
            int width = scanner.nextInt();
            int heigth = scanner.nextInt();
            scanner.nextLine();
            String[] maze = new String[heigth];
            int[][] nodes = new int[200][3];
            int num_nodes = read_maze(maze, nodes, heigth, width, scanner);

            int[][] distance_matrix = new int[num_nodes][num_nodes];

            for (int i = 0; i < num_nodes; i++) {
                distance_matrix[i][i] = 0;
                for (int ii = 0; ii < num_nodes; ii++) {
                    if (i != ii) {
                        // System.out.println("BFS");
                        distance_matrix[i][ii] = distance_matrix[ii][i] =
                            BFS(maze, width, heigth, nodes[i], nodes[ii]);
                    }
                }
            }

            System.out.println(prim(distance_matrix));
        }
        scanner.close();
    }
}