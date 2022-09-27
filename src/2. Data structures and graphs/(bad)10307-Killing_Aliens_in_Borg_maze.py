# https://onlinejudge.org/external/103/10307.pdf


def shortest_path(graph, start, end):
    paths = [[(start, start)]]
    visited = [start]

    for path in paths:
        current_node = path[-1][1]
        a = [
            (current_node[0] + 1, current_node[1]),
            (current_node[0] - 1, current_node[1]),
            (current_node[0], current_node[1] + 1),
            (current_node[0], current_node[1] - 1),
        ]
        next_nodes = [i for i in a if (not (i in visited) and graph[i[0]][i[1]] != "#")]

        if end in next_nodes:
            path.append((current_node, end))
            return (start, end, len(path[1:]))

        for next_node in next_nodes:
            # [:] is so it get value not referance
            blub = path[:]
            blub.append((current_node, next_node))
            paths.append(blub)
            # Add already visited nodes
            visited.append(next_node)

        # pop so less memory usage
        # doesn't work with python for (each), and im too lazy to change it now
        # paths.pop(0)

    # Should never happen in this case
    return []


def MST(graph, start):
    nodes = []
    stack = [(start, 0)]

    while stack:
        current_node = stack.pop()
        if not any(current_node[0] == node for (node, node_weight) in nodes):
            nodes.append(current_node)

        stack += [
            (j, weight)
            for (i, j, weight) in graph
            if i == current_node[0]
            and not any(j == node for (node, node_weight) in nodes)
        ]
        stack.sort(key=lambda a: a[1], reverse=True)

    return nodes


def main():
    cases = int(input())
    while cases:
        width, height = [int(x) for x in input().split(" ")]

        matrix = [input() for x in range(height)]

        nodes = [
            (i, j)
            for i, matrix_i in enumerate(matrix)
            for j, value in enumerate(matrix_i)
            if value == "A" or value == "S"
        ]
        start = [
            (i, j)
            for i, matrix_i in enumerate(matrix)
            for j, value in enumerate(matrix_i)
            if value == "S"
        ]
        if start:
            start = start[0]

        graph = []
        for node in nodes:
            for node2 in nodes:
                if node != node2:
                    graph.append(shortest_path(matrix, node, node2))

        tree = MST(graph, start)
        print(sum([weight for (i, weight) in tree]))

        cases -= 1


if __name__ == "__main__":
    main()
