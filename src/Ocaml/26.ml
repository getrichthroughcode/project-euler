let length_of_recurring_factor n =
  let marker = Array.make n 0 in
  let rec aux dividend out =
    let remainder = dividend mod n in
    if marker.(remainder) = 0 then begin
      marker.(remainder) <- 1;
      let new_dividend = 10 * remainder in
      Printf.printf "%d\n" (new_dividend / n);
      aux new_dividend (out + 1)
    end else
      out
  in
  aux 1 0

let () =
  let n = 1000 in
  let max = ref 0 in
  let result = ref 0 in
  for k = 2 to n - 1 do
    let length = length_of_recurring_factor k in
    if !max < length then begin
      max := length;
      result := k
    end
  done;
  Printf.printf "Longest recurring cycle is obtained for this integer: %d\n" !result
