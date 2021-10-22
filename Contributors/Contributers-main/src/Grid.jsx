import React from "react";
import { Row, Col } from "react-bootstrap";
import Mycard from "./Mycard";
import { useAsync } from "react-async";

const fetchPerson = async ({ id }, { signal }) => {
  const response = await fetch(
    `https://api.github.com/repos/geeks-hub-nith/C-Plus-Plus/contributors
  `,
    { signal }
  );
  if (!response.ok) throw new Error(response.status);
  return response.json();
};

const CreateGrid = () => {
  const { data, error } = useAsync({ promiseFn: fetchPerson });
  console.log(data);
  if (error) return error.message;
  if (data)
    return (
      <Row xs={1} md={3} className="g-4">
        {data.map((item) => (
          <Col>
            {" "}
            <Mycard
              name={item.login}
              html_url={item.html_url}
              contributions={item.contributions}
              avatar={item.avatar_url}
            />
          </Col>
        ))}
      </Row>
    );
  return null;
};

export default function Grid() {
  // var data=getData();

  //const { data, error } = useAsync({ promiseFn: fetchPerson ,id})
  // console.log(data)
  //data.map(Mycard);
  return (
    <div className="container">
      <CreateGrid />
    </div>
  );
}
