let best = 9999
let start = 0
let waiting = false

// Reset function to clear game state
function resetGame() {
    best = 9999
    start = 0
    waiting = false
    basic.clearScreen()
    basic.showString("Reset")
    basic.pause(1000)
    basic.clearScreen()
}

input.onButtonPressed(Button.A, function () {
    if (!waiting) {
        // Countdown with sound
        for (let i = 3; i > 0; i--) {
            basic.showNumber(i)
            music.playTone(Note.C, 200)
            basic.clearScreen()
            basic.pause(200)
        }
        // Random wait before "GO"
        basic.pause(randint(800, 2000))
        basic.showIcon(IconNames.Heart)
        music.playTone(Note.C, 500) // Buzzer tone at "GO!"
        start = input.runningTime()
        waiting = true
    }
})

input.onButtonPressed(Button.B, function () {
    if (waiting) {
        let reaction = input.runningTime() - start
        basic.clearScreen()
        basic.showNumber(reaction)
        if (reaction < best) {
            best = reaction
        }
        music.playTone(Note.C, 200)
        basic.pause(1000)
        basic.showString("Best")
        basic.showNumber(best)
        basic.pause(1000)
        basic.clearScreen()
        waiting = false
    } else {
        // Reset round if B is pressed again when not waiting
        resetGame()
    }
})

// A+B combination to show high score
input.onButtonPressed(Button.AB, function () {
    basic.clearScreen()
    basic.showString("High Score")
    basic.showNumber(best)
    basic.pause(2000)
    basic.clearScreen()
})