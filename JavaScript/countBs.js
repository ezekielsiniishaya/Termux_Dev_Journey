function countBs(String) {
    let i = 0, j = 0
    while(i < String.length) {
        if (String[i] == 'B') {
            j++
        }
        i++
    }
    return j
}

console.log(countBs("Behavior"))
