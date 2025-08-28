func sortMatrix(grid [][]int) [][]int {
    n, m := len(grid), len(grid[0])
    diags := make(map[int][]int)

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            key := i - j
            diags[key] = append(diags[key], grid[i][j])
        }
    }

    for key, arr := range diags {
        if key < 0 {
            sort.Ints(arr)
        } else {
            sort.Slice(arr, func(a, b int) bool { return arr[a] > arr[b] })
        }
        diags[key] = arr
    }

    idx := make(map[int]int)
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            key := i - j
            grid[i][j] = diags[key][idx[key]]
            idx[key]++
        }
    }
    return grid
}