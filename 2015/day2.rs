use std::fs::File;
use std::io::prelude::*;
use std::io::BufReader;
use std::path::Path;

fn main() {
   // let test_input = "1x1x10";
	let path = Path::new("input.txt");
    let display = path.display();
	
	let file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", display, why),
        Ok(file) => file,
    };
	
	let reader = BufReader::new(file);
    let lines: Vec<_> = reader.lines().collect();


	let mut total_area = 0;
	let mut total_ribbon = 0;
    for ln in lines {
        let mut area = 0;
		let (mut l, mut w, mut h) = (0, 0, 0);
		
		let nl = ln.unwrap();
		let dem = nl.split("x");
		let mut current_side = 0;
		let mut ribbon = 0;
		for side in dem{
			if current_side == 0{
				l = side.parse().unwrap();    
			}else if current_side == 1{
				w = side.parse().unwrap();
			}else if current_side == 2{
				h = side.parse().unwrap();
			}
			current_side += 1;
	   }
	   let lw = l*w;
	   let wh = w*h;
	   let hl = h*l;
	   let volume = h*w*l;
		   
	   if lw <= wh && lw <= hl{
		   area = 2 * (lw + wh + hl) + lw;
		   ribbon = l + l + w + w + volume;
	   }else if wh <= lw && wh <= hl{
		   area = 2 * (lw + wh + hl) + wh;
		   ribbon = w + w + h + h + volume;
	   }else if hl <= lw && hl <= wh{
		   area = 2 * (lw + wh + hl) + hl;
		   ribbon  = h + h + l + l + volume;
	   }
	   total_area += area;
	   total_ribbon += ribbon;
		println!("Area: {area}");
		println!("Ribbon: {ribbon}");
	}
	println!("Total Area: {total_area}");
	println!("Total Ribbon: {total_ribbon}");
   /*for line 
   break line into l w h by x
   find each lw,wh, hl
   get lowest
   math*/
   
   /*p2
   same checks but length = 1+1+2+2
   
   
   */
}