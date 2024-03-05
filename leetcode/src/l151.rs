fn reverse_words(mut s: String) -> String {
    // remove spaces
    let mut words: Vec<String> = vec![];
    let mut cur_word: Option<Vec<u8>> = None;
    for i in 0..s.as_bytes().len() {
        let cw = s.as_bytes()[i];
        if s.as_bytes()[i] == b' ' {
            if let Some(w) = cur_word.take() {
                words.push(std::str::from_utf8(w.as_slice()).unwrap().to_owned());
            }
        } else {
            if let Some(mut w) = cur_word.take() {
                w.push(cw);
                cur_word = Some(w);
            } else {
                cur_word = Some(vec![cw]);
            }
        }
    }
    if let Some(w) = cur_word.take() {
        words.push(std::str::from_utf8(w.as_slice()).unwrap().to_owned());
    }
    let mut s = String::new();
    while let Some(word) = words.pop() {
        s.push_str(word.as_str());
        if words.len() > 0 {
            s.push(' ');
        }
    }
    s
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test() {
        let s = reverse_words(" the sky is blue".to_owned());
        println!("{}", s);
    }
}
