function minTimeToType(word: string): number {
    let totalTime = 0;
    let currentPos = 0;

    console.log(`Initial position: '${String.fromCharCode(97)}' (idx ${currentPos})`)
    console.log(`Typing word: ${word}`);

    for (let i = 0; i < word.length; i++) {
        const targetChar = word[i];
        console.log(`Character ${i + 1}: '${targetChar}'`);
        console.log(`  Current pointer at '${String.fromCharCode(currentPos + 97)}' (index ${currentPos})`);

        const targetPos = targetChar.charCodeAt(0) - "a".charCodeAt(0);
        console.log(`  Target character '${targetChar}' is at index ${targetPos}`);

        const directDistance = Math.abs(currentPos - targetPos);
        console.log(`  Direct distance: ${directDistance}`);

        const circularDistance = 26 - directDistance;
        console.log(`  Circular distance: ${circularDistance}`);

        const moveTime = Math.min(directDistance, circularDistance);
        console.log(`  --> Move time: ${moveTime} second(s)`);
        console.log(`  --> Type time: 1 second`);

        totalTime += moveTime + 1;
        currentPos = targetPos;

        console.log(`  Total time so far: ${totalTime} seconds\n`);
    }

    console.log(`Finished typing. Total time: ${totalTime} seconds`);
    return totalTime;
};