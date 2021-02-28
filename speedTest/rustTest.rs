/*
  All credit to Vikram Mishra at https://github.com/insanebaba
  Thanks for the help!
*/

fn main() {
    let len = 10000;
    let mut to_sort = vec![0_i32; len];
    build(&mut to_sort);
    sort(&mut to_sort,len);
    // print!("{:?}",to_sort);
}

fn build(list: &mut Vec<i32>) {
    let mut len = list.len() as i32;
    for i in 0..list.len() {
        list[i]=len;
        len=len-1;
    }
}

fn sort(list: &mut Vec<i32> , len: usize) {
    let mut sorted = false;
    let mut i ;
    let mut temp;
    while !sorted {
        sorted=true;
        i = 0;
        while i < len - 1 {
            if list[i] > list[i+1]{
                temp = list[i+1];
                list[i+1]=list[i];
                list[i]=temp;
                sorted = false;
            }
            i+=1;
        }
    }
}
