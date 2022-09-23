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
            return path[1:]

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
    stack = [start]

    while stack:
        current_node = stack.pop()
        nodes.append(current_node)
        stack += [j for (i,j) in graph if i == current_node and not j in nodes]

        # stack.extend([j for (i, j) in edges if not j in nodes])

        # print(nodes)
        # print(stack)

    return nodes


def main():
    cases = int(input())
    while cases:
        width, height = [int(x) for x in input().split(" ")]

        matrix = [input() for x in range(height)]

        aliens = [
            (i, j)
            for i, matrix_i in enumerate(matrix)
            for j, value in enumerate(matrix_i)
            if value == "A"
        ]
        start = [
            (i, j)
            for i, matrix_i in enumerate(matrix)
            for j, value in enumerate(matrix_i)
            if value == "S"
        ]
        if start:
            start = start[0]

        graph = list(
            set().union(*[shortest_path(matrix, start, alien) for alien in aliens])
        )
        # print(graph)
        print(len(MST(graph, start)))

        cases -= 1


if __name__ == "__main__":
    main()
