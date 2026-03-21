use std::fs;
use std::path::Path;

fn read_trimmed(path: &Path) -> Option<String> {
    fs::read_to_string(path).ok().map(|s| s.trim().to_string())
}

fn main() {
    let target = std::env::args().nth(1).expect("usage: procwatch <process_name>");

    let proc_dir = Path::new("/proc");

    for entry in fs::read_dir(proc_dir).expect("failed to read /proc") {
        let entry = entry.expect("bad entry");
        let file_name = entry.file_name();
        let pid_str = file_name.to_string_lossy();

        if !pid_str.chars().all(|c| c.is_ascii_digit()) {
            continue;
        }

        let pid_path = entry.path();
        let comm_path = pid_path.join("comm");

        let comm = match read_trimmed(&comm_path) {
            Some(c) => c,
            None => continue,
        };

        if comm != target {
            continue;
        }

        println!("process: {}", comm);
        println!("pid: {}", pid_str);
        println!("threads:");

        let task_dir = pid_path.join("task");
        if let Ok(tasks) = fs::read_dir(task_dir) {
            for task in tasks {
                let task = task.expect("bad task entry");
                let tid = task.file_name().to_string_lossy().to_string();
                let tcomm = read_trimmed(&task.path().join("comm"))
                    .unwrap_or_else(|| "<unknown>".to_string());

                println!("  tid={} comm={}", tid, tcomm);
            }
        }

        return;
    }

    eprintln!("process '{}' not found", target);
    std::process::exit(1);
}
