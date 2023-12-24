use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

fn main() {
    
	let path = Path::new("input.txt");
    let display = path.display();
	
	let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", display, why),
        Ok(file) => file,
    };
	
	let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(why) => panic!("couldn't read {}: {}", display, why),
        Ok(_) => print!("{} contains:\n{}", display, s),
    }
   //for line 
   //break line into l w h by x
   //find each lw,wh, hl
   //get lowest
   //math
   let input = "^>v<";
   let mut houses = vec![[0,0]];
   //let mut seen: HashMap<vec, bool> = HashMap::new();
   
   let mut santa_loc = [0,0];
   let mut robo_loc = [0,0];
   
   let mut id = true;
   
   for c in s.chars(){
	   if c == '^'{
		   if id {
			santa_loc[1] -= 1;
		   }else{
			robo_loc[1] -=1;
		   }
		}else if c == 'v'{
			if id{
			santa_loc[1] += 1;
			}else{
			robo_loc[1] += 1;
			}
		}else if c == '<'{
			if id{
			santa_loc[0] -= 1;
			}else{
				robo_loc[0] -=1;
			}
		} else if c == '>'{
			if id{
			santa_loc[0] += 1;
			}else{
			robo_loc[0] += 1;
			}
		}
		if id{
		houses.push(santa_loc);
		}else{
			houses.push(robo_loc);
		}
	   id = !id;
   }
   println!("{:?}", houses);
   houses.sort_by(|x, y| y[0].cmp(&x[0]).then(y[1].cmp(&x[1])));
	println!("{:?}", houses);

   houses.dedup();
   let house_num = houses.len();
   
 
    println!("Houses: {house_num}");
}