const std = @import("std");
const utils = @import("./utils.zig");

fn solution(path: []const u8) !u64 {
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    var lines = try utils.LineReader.init(allocator, path);
    defer lines.deinit();

    while (lines.next()) |line| {
        const line_trim = std.mem.trimRight(u8, line, "\r");
        _ = line_trim;
        // DO CALC HERE
    }

    return 0;
}

test "day 4 - part 1 - example" {
    const path = "../inputs/2024/04_example.txt";
    try std.testing.expectEqual(18, try solution(path));
}

// test "day 4 - part 1" {
//     const path = "../inputs/2024/04_input.txt";
//     try std.testing.expectEqual(163931492, try solution(path));
// }
//
// test "day 4 - part 2 - example" {
//     const path = "../inputs/2024/04_example.txt";
//     try std.testing.expectEqual(48, try solution(path));
// }
//
// test "day 4 - part 2" {
//     const path = "../inputs/2024/04_input.txt";
//     try std.testing.expectEqual(76911921, try solution(path));
// }
