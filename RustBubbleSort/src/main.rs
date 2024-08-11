use std::{fs::File, io::{self, BufRead}, time::Instant};

fn main() {
    // Path to the text file
    let path = "random_numbers.txt";

    // Measure time taken to open and read the file
    let start = Instant::now();
    let file = File::open(&path).expect("Failed to open file");
    let reader = io::BufReader::new(file);
    let mut numbers: Vec<i32> = reader.lines()
        .map(|line| line.expect("Failed to read line").trim().parse().expect("Failed to parse integer"))
        .collect();
    let duration = start.elapsed();
    println!("Time taken to read file: {:.2?} seconds", duration);

    // Measure time taken by bubble_sort
    bubble_sort(&mut numbers);


}

fn bubble_sort(arr: &mut [i32]) {
    let start = Instant::now();
    let len = arr.len();
    let mut swap_count = 0;
    let mut i = 0;

    while i < len {
        let mut swap_required = false;
        let mut j = 0;

        while j < len - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
                swap_count += 1;
                swap_required = true;
            }
            j += 1;
        }

        if !swap_required {
            break;
        }
        i += 1;
    }

    println!("Swap Count: {}", swap_count);
    let duration = start.elapsed();
    println!("Time taken for bubble sort: {:.2?} seconds", duration);
}
