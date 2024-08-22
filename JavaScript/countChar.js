function countChar(String, c) {
    let i = 0, j = 0
    while(i < String.length) {
        if (String[i] == c) {
            j++
        }
        i++
    }
    return j
}

console.log(countChar("Behavhe", "h"))
